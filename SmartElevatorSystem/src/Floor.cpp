/*
 * Context for Floor.cpp
 *
 * REQUIREMENT: 
 *   Implement the Floor class representing building levels.
 * 
 * DESIGN: 
 *   Define initialization and access functions for a floor level.
 * 
 * IMPLEMENTED: 
 *   Wrote default and parameterized constructors setting the floor level, and accessor.
 * 
 * RESULT: 
 *   Floor levels can be set and queried.
 */

#include "Floor.h"

Floor::Floor() : floorNumber(0) {}

Floor::Floor(int floorNum) : floorNumber(floorNum) {}

int Floor::getFloorNumber() const {
    return floorNumber;
}
