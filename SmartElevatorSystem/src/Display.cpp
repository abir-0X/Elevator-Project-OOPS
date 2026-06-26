/*
 * STAR Context for Display.cpp
 *
 * SITUATION: 
 *   Implement console formatting for outputting building status details.
 * 
 * TASK: 
 *   Implement the static display output functions for elevator states.
 * 
 * ACTION: 
 *   Iterated through all elevators in the building and printed their properties in a readable format.
 * 
 * RESULT: 
 *   Console output prints the active status details of all simulated elevator cars.
 */

#include "Display.h"
#include <iostream>

void Display::showStatus(const Building& building) {
    std::cout << "\n================= ELEVATOR SYSTEM STATUS =================\n";
    const auto& elevators = building.getElevators();
    for (const auto& elevator : elevators) {
        std::string dirStr = "IDLE";
        if (elevator.getDirection() == Direction::UP) dirStr = "UP";
        else if (elevator.getDirection() == Direction::DOWN) dirStr = "DOWN";

        std::string stateStr = "IDLE";
        if (elevator.getState() == ElevatorState::MOVING) stateStr = "MOVING";
        else if (elevator.getState() == ElevatorState::DOOR_OPEN) stateStr = "DOOR_OPEN";

        std::string doorStr = elevator.getIsDoorOpen() ? "OPEN" : "CLOSED";

        std::cout << "Elevator #" << elevator.getId() 
                  << " | Current Floor: " << elevator.getCurrentFloor()
                  << " | State: " << stateStr
                  << " | Direction: " << dirStr
                  << " | Door: " << doorStr
                  << " | Active Requests: " << elevator.getRequests().size() << "\n";
    }
    std::cout << "==========================================================\n\n";
}
