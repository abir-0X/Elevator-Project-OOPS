/*
 * Context for Floor.h
 *
 * REQUIREMENT: 
 *   Each building floor needs to be represented as an object to house floor-specific operations (like calling elevators).
 * 
 * DESIGN: 
 *   Define a Floor class containing the floor number and constructor/getter interfaces.
 * 
 * IMPLEMENTED: 
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
    Floor();
    Floor(int floorNum);
    int getFloorNumber() const;
};

#endif // FLOOR_H
