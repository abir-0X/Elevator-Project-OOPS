/*
 * Context for Elevator.cpp
 *
 * REQUIREMENT: 
 *   Implement initialization, state transitions, movement, and request queuing logic for a single elevator cabin.
 * 
 * DESIGN: 
 *   Define methods for moving up/down, opening/closing doors, checking active requests, and sorting requests using the SCAN algorithm.
 * 
 * IMPLEMENTED: 
 *   Wrote constructor, enums integration, moveUp, moveDown, stop, openDoor, closeDoor, sortRequests, and step methods.
 * 
 * RESULT: 
 *   Elevator objects process requests, transition states (Idle -> Moving -> Door Open -> Idle) and update positions properly.
 */

#include "Elevator.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

Elevator::Elevator(int id, int startFloor) 
    : id(id), currentFloor(Floor(startFloor)), direction(Direction::IDLE), state(ElevatorState::IDLE), isDoorOpen(false) {}

int Elevator::getId() const {
    return id;
}

int Elevator::getCurrentFloor() const {
    return currentFloor.getFloorNumber();
}

const Floor& Elevator::getCurrentFloorObject() const {
    return currentFloor;
}

Direction Elevator::getDirection() const {
    return direction;
}

ElevatorState Elevator::getState() const {
    return state;
}

bool Elevator::getIsDoorOpen() const {
    return isDoorOpen;
}

const vector<Request>& Elevator::getRequests() const {
    return requests;
}

optional<int> Elevator::getNextDestination() const {
    if (requests.empty()) {
        return nullopt;
    }
    return requests.front().getDestinationFloor();
}

void Elevator::setCurrentFloor(const Floor& floor) {
    currentFloor = floor;
}

void Elevator::setDirection(Direction dir) {
    direction = dir;
}

void Elevator::setIsDoorOpen(bool open) {
    isDoorOpen = open;
}

void Elevator::setState(ElevatorState st) {
    state = st;
}

void Elevator::addRequest(const Request& req) {
    for (const auto& r : requests) {
        if (r.getDestinationFloor() == req.getDestinationFloor() && r.getDirection() == req.getDirection()) {
            cout << "[Warning] Duplicate request for floor " << req.getDestinationFloor() << " ignored.\n";
            return;
        }
    }
    requests.push_back(req);
    sortRequests();
}

void Elevator::clearRequests() {
    requests.clear();
}

void Elevator::moveUp() {
    if (isDoorOpen) {
        closeDoor();
    }
    direction = Direction::UP;
    state = ElevatorState::MOVING;
    currentFloor = Floor(currentFloor.getFloorNumber() + 1);
}

void Elevator::moveDown() {
    if (isDoorOpen) {
        closeDoor();
    }
    direction = Direction::DOWN;
    state = ElevatorState::MOVING;
    currentFloor = Floor(currentFloor.getFloorNumber() - 1);
}

void Elevator::stop() {
    direction = Direction::IDLE;
    state = ElevatorState::IDLE;
}

void Elevator::openDoor() {
    state = ElevatorState::DOOR_OPEN;
    isDoorOpen = true;
}

void Elevator::closeDoor() {
    isDoorOpen = false;
    if (direction == Direction::IDLE) {
        state = ElevatorState::IDLE;
    } else {
        state = ElevatorState::MOVING;
    }
}

bool Elevator::hasRequests() const {
    return !requests.empty();
}

void Elevator::sortRequests() {
    if (requests.empty()) return;

    int curr = currentFloor.getFloorNumber();
    Direction dir = direction;

    sort(requests.begin(), requests.end(), [curr, dir](const Request& a, const Request& b) {
        int destA = a.getDestinationFloor();
        int destB = b.getDestinationFloor();

        // If IDLE, sort by proximity
        if (dir == Direction::IDLE) {
            return abs(destA - curr) < abs(destB - curr);
        }

        // If UP
        if (dir == Direction::UP) {
            bool aIsAbove = destA >= curr;
            bool bIsAbove = destB >= curr;
            if (aIsAbove && !bIsAbove) return true;
            if (!aIsAbove && bIsAbove) return false;
            if (aIsAbove && bIsAbove) return destA < destB;
            return destA > destB;
        }

        // If DOWN
        if (dir == Direction::DOWN) {
            bool aIsBelow = destA <= curr;
            bool bIsBelow = destB <= curr;
            if (aIsBelow && !bIsBelow) return true;
            if (!aIsBelow && bIsBelow) return false;
            if (aIsBelow && bIsBelow) return destA > destB;
            return destA < destB;
        }

        return false;
    });
}

void Elevator::step() {
    if (requests.empty()) {
        stop();
        return;
    }

    int target = requests.front().getDestinationFloor();
    int curr = currentFloor.getFloorNumber();

    if (curr == target) {
        openDoor();
        // Remove all requests for this floor to avoid duplicate stops
        requests.erase(
            remove_if(requests.begin(), requests.end(), 
                [target](const Request& r) { return r.getDestinationFloor() == target; }),
            requests.end()
        );
    } else {
        if (isDoorOpen) {
            closeDoor();
        }
        if (curr < target) {
            moveUp();
        } else {
            moveDown();
        }
    }
}
