/*
 * STAR Context for Scheduler.h
 *
 * SITUATION: 
 *   In a multi-elevator system, external floor calls need to be routed to the most optimal elevator
 *   to minimize wait times and maximize efficiency.
 * 
 * TASK: 
 *   Define a Scheduler class encapsulating decision logic (assignElevator, findNearest, dispatch)
 *   following LLD and SOLID principles.
 * 
 * ACTION: 
 *   Declared standard public interfaces to assign requests to elevators within a Building.
 * 
 * RESULT: 
 *   The Scheduler interface is established, decoupling dispatching logic from Building/Elevator classes.
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Building.h"
#include "Request.h"

class Scheduler {
public:
    // Decides and assigns the request to the best elevator in the building
    void assignElevator(const Request& req, Building& building);

    // Dispatches a request directly to a specific elevator (e.g., for internal requests)
    void dispatch(const Request& req, Elevator& elevator);

private:
    // Finds the index of the most optimal elevator for the given request
    int findNearest(const Request& req, const Building& building);
};

#endif // SCHEDULER_H
