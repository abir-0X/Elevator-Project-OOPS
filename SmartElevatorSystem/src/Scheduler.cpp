/*
 * Context for Scheduler.cpp
 *
 * REQUIREMENT: 
 *   Coordinate the dispatching of requests to the best available elevator.
 * 
 * DESIGN: 
 *   Delegate assignment calls to a pluggable ISchedulingAlgorithm strategy object (Dependency Inversion).
 * 
 * IMPLEMENTED: 
 *   Implemented constructors, assignElevator delegation, and direct dispatch routines.
 * 
 * RESULT: 
 *   Requests are successfully scheduled and processed without scheduler logic being coupled to specific algorithms.
 */

#include "Scheduler.h"
#include "NearestScanScheduler.h"
#include <iostream>

using namespace std;

Scheduler::Scheduler() 
    : algorithm(make_unique<NearestScanScheduler>()) {}

Scheduler::Scheduler(unique_ptr<ISchedulingAlgorithm> algo) 
    : algorithm(move(algo)) {}

void Scheduler::assignElevator(const Request& req, Building& building) {
    int idx = algorithm->findNearest(req, building);
    if (idx != -1) {
        cout << "[Scheduler] Request at floor " << req.getSourceFloor() 
             << " assigned to Elevator #" << building.getElevators()[idx].getId() << "\n";
        building.getMutableElevators()[idx].addRequest(req);
    }
}

void Scheduler::dispatch(const Request& req, Elevator& elevator) {
    cout << "[Scheduler] Direct dispatch to Elevator #" << elevator.getId() 
         << " for floor " << req.getDestinationFloor() << "\n";
    elevator.addRequest(req);
}
