/*
 * STAR Context for Scheduler.cpp
 *
 * SITUATION: 
 *   Implement request allocation logic to route floor calls to the best elevator cabin.
 * 
 * TASK: 
 *   Implement findNearest cost function, assignElevator dispatch routine, and direct dispatch method.
 * 
 * ACTION: 
 *   Written cost logic evaluating elevator state, matching movement directions, and penalizing 
 *   opposite moves. Added routing delegation to the selected elevator.
 * 
 * RESULT: 
 *   Requests are dynamically routed to the most efficient elevator cabin, reducing user wait times.
 */

#include "Scheduler.h"
#include <cmath>
#include <climits>
#include <iostream>

void Scheduler::assignElevator(const Request& req, Building& building) {
    int idx = findNearest(req, building);
    if (idx != -1) {
        std::cout << "[Scheduler] Request at floor " << req.getSourceFloor() 
                  << " assigned to Elevator #" << building.getElevators()[idx].getId() << "\n";
        building.getMutableElevators()[idx].addRequest(req);
    }
}

void Scheduler::dispatch(const Request& req, Elevator& elevator) {
    std::cout << "[Scheduler] Direct dispatch to Elevator #" << elevator.getId() 
              << " for floor " << req.getDestinationFloor() << "\n";
    elevator.addRequest(req);
}

int Scheduler::findNearest(const Request& req, const Building& building) {
    const auto& elevators = building.getElevators();
    if (elevators.empty()) return -1;

    int bestElevatorIndex = 0;
    int minCost = INT_MAX;

    int src = req.getSourceFloor();
    int reqDir = req.getDirection();

    for (size_t i = 0; i < elevators.size(); ++i) {
        const auto& elevator = elevators[i];
        int curr = elevator.getCurrentFloor();
        Direction dir = elevator.getDirection();

        int cost = 0;

        // 1. Idle elevator preference
        if (dir == Direction::IDLE) {
            cost = std::abs(curr - src);
        }
        // 2. Elevator is moving UP
        else if (dir == Direction::UP) {
            if (src >= curr && reqDir == 1) {
                // Moving in same direction and request is ahead
                cost = src - curr;
            } else {
                // Large penalty if request is behind or opposite direction
                cost = 100 + std::abs(curr - src);
            }
        }
        // 3. Elevator is moving DOWN
        else if (dir == Direction::DOWN) {
            if (src <= curr && reqDir == -1) {
                // Moving in same direction and request is ahead
                cost = curr - src;
            } else {
                // Large penalty
                cost = 100 + std::abs(curr - src);
            }
        }

        if (cost < minCost) {
            minCost = cost;
            bestElevatorIndex = i;
        }
    }

    return bestElevatorIndex;
}
