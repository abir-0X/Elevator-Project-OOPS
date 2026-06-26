/*
 * STAR Context for main.cpp
 *
 * SITUATION: 
 *   Verifying Chapter 2 Relationships. Need to ensure Building holds Floor/Elevator collections
 *   properly, Elevator encapsulates a Floor object, and Elevator serves a list of Requests.
 * 
 * TASK: 
 *   Update main.cpp to populate and assign Requests to Elevators, verifying the HAS-A and serves relationships.
 * 
 * ACTION: 
 *   Created elevator Requests, added them to the elevators inside the building, and displayed status.
 * 
 * RESULT: 
 *   Active request counts are displayed for each elevator, showing successful object interaction.
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

    // Verify Chapter 2 relationships by adding requests to elevators
    auto& mutableElevators = building.getMutableElevators();
    if (mutableElevators.size() >= 2) {
        // Elevator 0 gets an internal request to floor 5
        mutableElevators[0].addRequest(Request(0, 5, 1, true));
        // Elevator 1 gets an external request from floor 3 to floor 8 going UP
        mutableElevators[1].addRequest(Request(3, 8, 1, false));
    }

    // Show status
    Display::showStatus(building);

    return 0;
}
