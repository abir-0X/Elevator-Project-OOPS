/*
 * STAR Context for Floor.cpp
 *
 * SITUATION: 
 *   Implement the behavior of Floor objects.
 * 
 * TASK: 
 *   Define initialization and access functions for a floor.
 * 
 * ACTION: 
 *   Wrote constructor setting the floor level and accessor returning it.
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
