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

class Elevator {
private:
    int id;
    int currentFloor;
    int direction; // -1 for DOWN, 0 for IDLE, 1 for UP
    bool isDoorOpen;

public:
    Elevator(int id, int startFloor = 0);

    // Getters
    int getId() const;
    int getCurrentFloor() const;
    int getDirection() const;
    bool getIsDoorOpen() const;

    // Setters
    void setCurrentFloor(int floor);
    void setDirection(int dir);
    void setIsDoorOpen(bool open);
};

#endif // ELEVATOR_H
