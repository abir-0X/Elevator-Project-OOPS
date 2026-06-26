/*
 * Context for Scheduler.h
 *
 * REQUIREMENT: 
 *   In a multi-elevator system, external floor calls need to be routed to the most optimal elevator
 *   to minimize wait times and maximize efficiency.
 * 
 * DESIGN: 
 *   Define a Scheduler class encapsulating decision logic (assignElevator, findNearest, dispatch)
 *   following LLD and SOLID principles.
 * 
 * IMPLEMENTED: 
 *   Declared standard public interfaces to assign requests to elevators within a Building.
 * 
 * RESULT: 
 *   The Scheduler interface is established, decoupling dispatching logic from Building/Elevator classes.
 */


#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Building.h"
#include "Request.h"
#include "ISchedulingAlgorithm.h"
#include <memory>

class Scheduler {
private:
    std::unique_ptr<ISchedulingAlgorithm> algorithm;

public:
    // Default constructor (uses NearestScanScheduler)
    Scheduler();

    // Constructor enabling dependency injection
    Scheduler(std::unique_ptr<ISchedulingAlgorithm> algo);

    // Decides and assigns the request to the best elevator in the building
    void assignElevator(const Request& req, Building& building);

    // Dispatches a request directly to a specific elevator (e.g., for internal requests)
    void dispatch(const Request& req, Elevator& elevator);
};

#endif // SCHEDULER_H
