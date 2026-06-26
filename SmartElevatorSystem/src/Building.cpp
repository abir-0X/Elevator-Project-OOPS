/*
 * STAR Context for Building.cpp
 *
 * SITUATION: 
 *   Implement the Building container methods.
 * 
 * TASK: 
 *   Write the constructor to initialize collections of Floor and Elevator objects based on counts.
 * 
 * ACTION: 
 *   Created vectors and populated them in a loop with appropriate floor levels and elevator IDs.
 * 
 * RESULT: 
 *   The simulated building configuration is instantiated with all structural floors and elevator cabs.
 */

#include "Building.h"
using namespace std;

Building::Building(int numFloors, int numElevators) {
    // Populate floors 0 to numFloors-1
    for (int i = 0; i < numFloors; ++i) {
        floors.push_back(Floor(i));
    }
    // Populate elevators 0 to numElevators-1
    for (int i = 0; i < numElevators; ++i) {
        elevators.push_back(Elevator(i));
    }
}

const vector<Floor>& Building::getFloors() const {
    return floors;
}

const vector<Elevator>& Building::getElevators() const {
    return elevators;
}

vector<Elevator>& Building::getMutableElevators() {
    return elevators;
}
