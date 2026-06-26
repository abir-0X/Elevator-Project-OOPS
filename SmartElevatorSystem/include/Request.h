/*
 * STAR Context for Request.h
 *
 * SITUATION: 
 *   Users create requests to summon or steer elevators. We need a class to model this input request.
 * 
 * TASK: 
 *   Define a Request class encapsulating source floor, destination floor, direction, and call origin.
 * 
 * ACTION: 
 *   Declared member variables for source, destination, direction, and internal/external flags.
 * 
 * RESULT: 
 *   Requests are standardized into objects that can be queued and sorted.
 */

#ifndef REQUEST_H
#define REQUEST_H

class Request {
private:
    int sourceFloor;
    int destinationFloor;
    int direction; // -1 for DOWN, 0 for NONE, 1 for UP
    bool isInternal; // true if made inside elevator, false if outside hall

public:
    Request(int src, int dest, int dir, bool internal);

    int getSourceFloor() const;
    int getDestinationFloor() const;
    int getDirection() const;
    bool getIsInternal() const;
};

#endif // REQUEST_H
