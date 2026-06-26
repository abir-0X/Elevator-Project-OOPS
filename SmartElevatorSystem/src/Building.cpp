/*
 * Context for Building.cpp
 *
 * REQUIREMENT: 
 *   Implement the Building class representing a building containing multiple floors and elevators.
 * 
 * DESIGN: 
 *   Keep collections of Floor and Elevator objects (composition) and expose getters and validation logic on instantiation.
 * 
 * IMPLEMENTED: 
 *   Wrote constructor with defensive checks (numFloors > 0, numElevators > 0) and standard collection accessors.
 * 
 * RESULT: 
 *   The Building configuration is safely initialized and can be queried.
 */

#include "Building.h"
#include "Exceptions.h"

using namespace std;

Building::Building(int numFloors, int numElevators) {
    if (numFloors <= 0) {
        throw InvalidFloorException("Building must have at least 1 floor.");
    }
    if (numElevators <= 0) {
        throw InvalidElevatorException("Building must have at least 1 elevator.");
    }

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

