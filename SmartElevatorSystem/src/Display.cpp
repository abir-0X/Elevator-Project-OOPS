/*
 * Context for Display.cpp
 *
 * REQUIREMENT: 
 *   Format and print the status of elevators in the building to the console.
 * 
 * DESIGN: 
 *   Create a static helper method to display elevator states, directions, door statuses, and request queues.
 * 
 * IMPLEMENTED: 
 *   Iterated through all elevators in the building and printed their properties in a readable format.
 * 
 * RESULT: 
 *   Console output prints the active status details of all simulated elevator cars.
 */

#include "Display.h"
#include <iostream>

using namespace std;

void Display::showStatus(const Building& building) {
    cout << "\n================= ELEVATOR SYSTEM STATUS =================\n";
    const auto& elevators = building.getElevators();
    for (const auto& elevator : elevators) {
        string dirStr = "IDLE";
        if (elevator.getDirection() == Direction::UP) dirStr = "UP";
        else if (elevator.getDirection() == Direction::DOWN) dirStr = "DOWN";

        string stateStr = "IDLE";
        if (elevator.getState() == ElevatorState::MOVING) stateStr = "MOVING";
        else if (elevator.getState() == ElevatorState::DOOR_OPEN) stateStr = "DOOR_OPEN";

        string doorStr = elevator.getIsDoorOpen() ? "OPEN" : "CLOSED";

        cout << "Elevator #" << elevator.getId() 
             << " | Current Floor: " << elevator.getCurrentFloor()
             << " | State: " << stateStr
             << " | Direction: " << dirStr
             << " | Door: " << doorStr
             << " | Active Requests: " << elevator.getRequests().size() << "\n";
    }
    cout << "==========================================================\n\n";
}
