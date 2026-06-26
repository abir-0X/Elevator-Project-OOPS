/*
 * STAR Context for Elevator.h
 *
 * SITUATION: 
 *   Need a structured data type to represent an elevator cabin in the simulation.
 * 
 * TASK: 
 *   Define an encapsulated Elevator class holding basic state variables (ID, current floor,
 *   direction, door status) with constructors and clean accessors.
 * 
 * ACTION: 
 *   Declared standard private member variables and public inline/basic getters/setters.
 * 
 * RESULT: 
 *   The Elevator interface is established, enabling aggregation under Building and movement control.
 */

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>
#include <vector>
#include "Floor.h"
#include "Request.h"

class Elevator {
private:
    int id;
    Floor currentFloor;
    int direction; // -1 for DOWN, 0 for IDLE, 1 for UP
    bool isDoorOpen;
    std::vector<Request> requests;

public:
    Elevator(int id, int startFloor = 0);

    // Getters
    int getId() const;
    int getCurrentFloor() const;
    const Floor& getCurrentFloorObject() const;
    int getDirection() const;
    bool getIsDoorOpen() const;
    const std::vector<Request>& getRequests() const;

    // Setters
    void setCurrentFloor(const Floor& floor);
    void setDirection(int dir);
    void setIsDoorOpen(bool open);

    // Request operations
    void addRequest(const Request& req);
    void clearRequests();
};

#endif // ELEVATOR_H
