/*
 * STAR Context for Floor.h
 *
 * SITUATION: 
 *   Each building floor needs to be represented as an object to house floor-specific operations (like calling elevators).
 * 
 * TASK: 
 *   Define a Floor class containing the floor number and constructor/getter interfaces.
 * 
 * ACTION: 
 *   Declared private member variables for floor ID/number and public member functions.
 * 
 * RESULT: 
 *   Floor models are ready to be instantiated and queried.
 */

#ifndef FLOOR_H
#define FLOOR_H

class Floor {
private:
    int floorNumber;

public:
    Floor(int floorNum);
    int getFloorNumber() const;
};

#endif // FLOOR_H
