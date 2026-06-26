/*
 * STAR Context for Request.cpp
 *
 * SITUATION: 
 *   Implement the getters and constructor of the Request class.
 * 
 * TASK: 
 *   Create initialization logic to capture user elevator calls correctly.
 * 
 * ACTION: 
 *   Wrote parameter constructor and standard accessors.
 * 
 * RESULT: 
 *   Requests can be constructed representing both cabin button clicks and floor panel clicks.
 */

#include "Request.h"

Request::Request(int src, int dest, int dir, bool internal)
    : sourceFloor(src), destinationFloor(dest), direction(dir), isInternal(internal) {}

int Request::getSourceFloor() const {
    return sourceFloor;
}

int Request::getDestinationFloor() const {
    return destinationFloor;
}

int Request::getDirection() const {
    return direction;
}

bool Request::getIsInternal() const {
    return isInternal;
}
