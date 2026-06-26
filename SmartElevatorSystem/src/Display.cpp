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
        if (elevator.getDirection() == 1) dirStr = "UP";
        else if (elevator.getDirection() == -1) dirStr = "DOWN";

        std::string doorStr = elevator.getIsDoorOpen() ? "OPEN" : "CLOSED";

        std::cout << "Elevator #" << elevator.getId() 
                  << " | Current Floor: " << elevator.getCurrentFloor()
                  << " | Direction: " << dirStr
                  << " | Door: " << doorStr << "\n";
    }
    std::cout << "==========================================================\n\n";
}
