/*
 * Context for Building.h
 *
 * REQUIREMENT: 
 *   A Building houses both the floors and the elevator cabins in the simulation.
 * 
 * DESIGN: 
 *   Define a Building class that coordinates elevators and floors, offering access interfaces.
 * 
 * IMPLEMENTED: 
 *   Declared std::vector containers of Floor and Elevator objects with constructors.
 * 
 * RESULT: 
 *   Building class provides a single system container to holds all other entity collections.
 */


#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "Floor.h"
#include "Elevator.h"

class Building {
private:
    std::vector<Floor> floors;
    std::vector<Elevator> elevators;

public:
    Building(int numFloors, int numElevators);

    const std::vector<Floor>& getFloors() const;
    const std::vector<Elevator>& getElevators() const;
    std::vector<Elevator>& getMutableElevators();
};

#endif // BUILDING_H
