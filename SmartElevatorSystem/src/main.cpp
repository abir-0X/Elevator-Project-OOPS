/*
 * STAR Context for main.cpp
 *
 * SITUATION: 
 *   Verifying Chapter 6 Complete Simulation. We need a continuous execution flow to tie all
 *   components together (Building, Elevators, Scheduler, Display) into an interactive application.
 * 
 * TASK: 
 *   Replace mock tests in main.cpp with a continuous command-line interface (CLI) menu that allows 
 *   users to enter floor calls, make cabin calls, step the simulation, and observe state updates.
 * 
 * ACTION: 
 *   Developed a console-based while loop with input validation, enabling external calls (assigned via Scheduler)
 *   and internal cabin button calls (direct dispatch), driving the elevators step-by-step.
 * 
 * RESULT: 
 *   The entire Smart Elevator system works together interactively in a complete, playable simulation.
 */

#include <bits/stdc++.h>
#include "Building.h"
#include "Display.h"
#include "Scheduler.h"

using namespace std;

#define int long long

int32_t main() {
    cout << "Smart Elevator System Simulator Initialized!" << endl;

    int numFloors = 10;
    int numElevators = 2;
    Building building(numFloors, numElevators);
    Scheduler scheduler;

    while (true) {
        cout << "\n================= SIMULATION MENU =================\n";
        cout << "1. Request Elevator (External / Floor Call)\n";
        cout << "2. Dispatch Elevator (Internal / Cabin Call)\n";
        cout << "3. Step Simulation (Advance 1 Time-step)\n";
        cout << "4. Show Elevator Status\n";
        cout << "5. Exit\n";
        cout << "Select option (1-5): ";
        
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        if (choice == 1) {
            int src, dest;
            cout << "Enter source floor (0-" << numFloors - 1 << "): ";
            cin >> src;
            cout << "Enter destination floor (0-" << numFloors - 1 << "): ";
            cin >> dest;

            if (src < 0 || src >= numFloors || dest < 0 || dest >= numFloors) {
                cout << "Invalid floor input. Floors must be between 0 and " << numFloors - 1 << ".\n";
                continue;
            }
            if (src == dest) {
                cout << "Source and destination floors cannot be the same.\n";
                continue;
            }

            int dir = (dest > src) ? 1 : -1;
            Request req(src, dest, dir, false);
            scheduler.assignElevator(req, building);
        }
        else if (choice == 2) {
            int elevatorId, dest;
            cout << "Enter Elevator ID (0-" << numElevators - 1 << "): ";
            cin >> elevatorId;
            cout << "Enter target floor (0-" << numFloors - 1 << "): ";
            cin >> dest;

            if (elevatorId < 0 || elevatorId >= numElevators) {
                cout << "Invalid Elevator ID.\n";
                continue;
            }
            if (dest < 0 || dest >= numFloors) {
                cout << "Invalid floor input.\n";
                continue;
            }

            auto& mutableElevators = building.getMutableElevators();
            Elevator& elevator = mutableElevators[elevatorId];
            if (elevator.getCurrentFloor() == dest) {
                cout << "Elevator is already at floor " << dest << ".\n";
                continue;
            }

            int dir = (dest > elevator.getCurrentFloor()) ? 1 : -1;
            Request req(elevator.getCurrentFloor(), dest, dir, true);
            scheduler.dispatch(req, elevator);
        }
        else if (choice == 3) {
            cout << "--- Stepping simulation ---" << endl;
            auto& mutableElevators = building.getMutableElevators();
            for (auto& elevator : mutableElevators) {
                elevator.step();
            }
            Display::showStatus(building);
        }
        else if (choice == 4) {
            Display::showStatus(building);
        }
        else if (choice == 5) {
            cout << "Exiting simulator. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid option. Select between 1 and 5.\n";
        }
    }

    return 0;
}
