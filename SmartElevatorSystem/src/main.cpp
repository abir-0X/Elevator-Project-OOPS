/*
 * STAR Context for main.cpp
 *
 * SITUATION: 
 *   Verifying Chapter 1 OOP structures. Need an execution flow that instantiates
 *   a Building containing Floors and Elevators, then displays their initial status.
 * 
 * TASK: 
 *   Update main.cpp to instantiate a Building and utilize the Display class to output
 *   initial elevator status, keeping the local coding style.
 * 
 * ACTION: 
 *   Created a Building instance with 10 floors and 2 elevators, then invoked
 *   Display::showStatus.
 * 
 * RESULT: 
 *   Successfully printed initial elevator status, verifying Chapter 1 classes compile and work.
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

    // Show initial status
    Display::showStatus(building);

    return 0;
}
