/*
 * Context for NearestScanScheduler.cpp
 *
 * REQUIREMENT: 
 *   Implement the nearest-elevator SCAN cost scheduling logic.
 * 
 * DESIGN: 
 *   Create a cost function that evaluates relative distance and direction alignment, applying penalties for moving away.
 * 
 * IMPLEMENTED: 
 *   Wrote the cost calculation loop searching for the minimum cost elevator.
 * 
 * RESULT: 
 *   SCAN cost strategy is implemented cleanly as a pluggable component.
 */

#include "NearestScanScheduler.h"
#include <cmath>
#include <climits>

using namespace std;

int NearestScanScheduler::findNearest(const Request& req, const Building& building) {
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
            cost = abs(curr - src);
        }
        // 2. Elevator is moving UP
        else if (dir == Direction::UP) {
            if (src >= curr && reqDir == 1) {
                cost = src - curr;
            } else {
                cost = 100 + abs(curr - src);
            }
        }
        // 3. Elevator is moving DOWN
        else if (dir == Direction::DOWN) {
            if (src <= curr && reqDir == -1) {
                cost = curr - src;
            } else {
                cost = 100 + abs(curr - src);
            }
        }

        if (cost < minCost) {
            minCost = cost;
            bestElevatorIndex = i;
        }
    }

    return bestElevatorIndex;
}
