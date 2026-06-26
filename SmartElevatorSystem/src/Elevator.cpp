/*
 * STAR Context for Elevator.cpp
 *
 * SITUATION: 
 *   Implement the behaviors and constructors defined in Elevator.h.
 * 
 * TASK: 
 *   Implement initialization logic and basic state transitions for a single elevator cabin.
 * 
 * ACTION: 
 *   Written simple constructors and setter/getter functions matching standard C++ LLD practices.
 * 
 * RESULT: 
 *   Elevator instances can now be dynamically initialized and manipulated by building and movement managers.
 */

#include "Elevator.h"

Elevator::Elevator(int id, int startFloor) 
    : id(id), currentFloor(Floor(startFloor)), direction(0), isDoorOpen(false) {}

int Elevator::getId() const {
    return id;
}

int Elevator::getCurrentFloor() const {
    return currentFloor.getFloorNumber();
}

const Floor& Elevator::getCurrentFloorObject() const {
    return currentFloor;
}

int Elevator::getDirection() const {
    return direction;
}

bool Elevator::getIsDoorOpen() const {
    return isDoorOpen;
}

const std::vector<Request>& Elevator::getRequests() const {
    return requests;
}

void Elevator::setCurrentFloor(const Floor& floor) {
    currentFloor = floor;
}

void Elevator::setDirection(int dir) {
    direction = dir;
}

void Elevator::setIsDoorOpen(bool open) {
    isDoorOpen = open;
}

void Elevator::addRequest(const Request& req) {
    requests.push_back(req);
}

void Elevator::clearRequests() {
    requests.clear();
}
