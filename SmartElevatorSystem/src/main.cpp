/*
 * STAR Context for main.cpp
 *
 * SITUATION: 
 *   Verifying Chapter 5 Scheduler. Need to verify that the Scheduler correctly calculates
 *   assignment costs for elevators and dispatches requests to the most optimal elevator
 *   based on proximity and movement direction.
 * 
 * TASK: 
 *   Update main.cpp to instantiate building with 2 elevators in specific states and submit
 *   external requests, checking if the Scheduler routes them to the correct elevator.
 * 
 * ACTION: 
 *   Configured Elevator 0 at floor 2 (UP) and Elevator 1 at floor 6 (DOWN), then submitted
 *   UP request at floor 3 and DOWN request at floor 5 using Scheduler::assignElevator.
 * 
 * RESULT: 
 *   Scheduler correctly routes the floor 3 UP request to Elevator 0, and the floor 5 DOWN
 *   request to Elevator 1, verifying the nearest-elevator algorithm.
 */

#include <bits/stdc++.h>
#include "Building.h"
#include "Display.h"
#include "Scheduler.h"

using namespace std;

#define int long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int32_t main() {
    fastio();
    cout << "Smart Elevator System Simulator Initialized!" << endl;

    // Create a building with 10 floors and 2 elevators
    Building building(10, 2);

    auto& mutableElevators = building.getMutableElevators();

    if (mutableElevators.size() >= 2) {
        // Pre-configure Elevator 0: at floor 2, moving UP
        mutableElevators[0].setCurrentFloor(Floor(2));
        mutableElevators[0].setDirection(Direction::UP);
        mutableElevators[0].setState(ElevatorState::MOVING);

        // Pre-configure Elevator 1: at floor 6, moving DOWN
        mutableElevators[1].setCurrentFloor(Floor(6));
        mutableElevators[1].setDirection(Direction::DOWN);
        mutableElevators[1].setState(ElevatorState::MOVING);

        cout << "--- Initial Custom States ---" << endl;
        Display::showStatus(building);

        Scheduler scheduler;

        // 1. Submit Request: UP from floor 3 (destination floor 7)
        // Should go to Elevator 0 (at floor 2, UP) instead of Elevator 1 (at floor 6, DOWN)
        cout << "--- Submitting UP call from Floor 3 ---" << endl;
        Request req1(3, 7, 1, false);
        scheduler.assignElevator(req1, building);

        // 2. Submit Request: DOWN from floor 5 (destination floor 1)
        // Should go to Elevator 1 (at floor 6, DOWN) instead of Elevator 0 (at floor 2, UP)
        cout << "--- Submitting DOWN call from Floor 5 ---" << endl;
        Request req2(5, 1, -1, false);
        scheduler.assignElevator(req2, building);

        // Display updated status
        cout << "--- Final Status ---" << endl;
        Display::showStatus(building);
    }

    return 0;
}
