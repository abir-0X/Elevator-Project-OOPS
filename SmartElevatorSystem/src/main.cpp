/*
 * STAR Context for main.cpp
 *
 * SITUATION: 
 *   Verifying Chapter 3 Elevator Movement. Need to verify that the elevator cabin can
 *   move up/down, stop, and open/close its doors while correctly transitioning its internal states.
 * 
 * TASK: 
 *   Update main.cpp to simulate elevator movement scenarios (move up, move down, open/close doors, stop)
 *   and render states after each step.
 * 
 * ACTION: 
 *   Invoked moveUp(), moveDown(), openDoor(), stop() methods on elevators and displayed state.
 * 
 * RESULT: 
 *   State transitions (Idle -> Moving -> Door Open -> Idle) and floor levels updated correctly in the console.
 */

#include <bits/stdc++.h>
#include "Building.h"
#include "Display.h"

using namespace std;

#define int long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int32_t main() {
    fastio();
    cout << "Smart Elevator System Simulator Initialized!" << endl;

    // Create a building with 10 floors and 2 elevators
    Building building(10, 2);

    auto& mutableElevators = building.getMutableElevators();

    // Verify initial status
    cout << "--- Initial Status ---" << endl;
    Display::showStatus(building);

    // Verify movement transitions
    if (mutableElevators.size() >= 2) {
        // Move elevator 0 UP two times
        cout << "--- Elevator 0 moves UP ---" << endl;
        mutableElevators[0].moveUp();
        Display::showStatus(building);

        cout << "--- Elevator 0 moves UP again ---" << endl;
        mutableElevators[0].moveUp();
        Display::showStatus(building);

        // Open door on Elevator 0
        cout << "--- Elevator 0 opens door ---" << endl;
        mutableElevators[0].openDoor();
        Display::showStatus(building);

        // Move elevator 1 DOWN from startFloor (0) -> goes to -1
        cout << "--- Elevator 1 moves DOWN ---" << endl;
        mutableElevators[1].moveDown();
        Display::showStatus(building);

        // Stop Elevator 1
        cout << "--- Elevator 1 stops ---" << endl;
        mutableElevators[1].stop();
        Display::showStatus(building);
    }

    return 0;
}
