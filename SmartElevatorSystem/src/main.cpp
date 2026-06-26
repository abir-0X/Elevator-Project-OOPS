/*
 * STAR Context for main.cpp
 *
 * SITUATION: 
 *   Verifying Chapter 4 Request Handling. Need to ensure that when multiple requests 
 *   are queued, they are correctly sorted using the SCAN algorithm, and the elevator
 *   processes them floor-by-floor.
 * 
 * TASK: 
 *   Update main.cpp to queue multiple requests (e.g. floors 3, 8, 1) and run steps
 *   to verify they are serviced in sorted order (1, then 3, then 8).
 * 
 * ACTION: 
 *   Added requests to Elevator 0, then ran step() inside a loop until requests were cleared.
 * 
 * RESULT: 
 *   Elevator services floor 1, then 3, then 8, opening/closing doors correctly without thrashing.
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

    if (!mutableElevators.empty()) {
        Elevator& elevator = mutableElevators[0];

        // Add out-of-order requests: floor 3, then 8, then 1
        cout << "--- Queueing requests for floors: 3, 8, 1 ---" << endl;
        elevator.addRequest(Request(0, 3, 1, true));
        elevator.addRequest(Request(0, 8, 1, true));
        elevator.addRequest(Request(0, 1, 1, true));

        // Display status to verify they are sorted
        Display::showStatus(building);

        // Run steps until all requests are completed
        int steps = 0;
        while (elevator.hasRequests() && steps < 15) {
            steps++;
            cout << "--- Step " << steps << " ---" << endl;
            elevator.step();
            Display::showStatus(building);
        }
    }

    return 0;
}
