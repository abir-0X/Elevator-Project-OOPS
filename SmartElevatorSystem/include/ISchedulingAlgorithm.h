/*
 * Context for ISchedulingAlgorithm.h
 *
 * REQUIREMENT: 
 *   Refactoring Scheduler for OCP and DIP. We need an abstract interface representing 
 *   elevator assignment algorithms to allow swapping scheduling strategies.
 * 
 * DESIGN: 
 *   Declare the ISchedulingAlgorithm base class with a virtual destructor and pure virtual 
 *   findNearest interface.
 * 
 * IMPLEMENTED: 
 *   Created ISchedulingAlgorithm.h declaring the virtual interface.
 * 
 * RESULT: 
 *   Decoupled scheduling algorithms from the Scheduler driver class, enabling polymorphic strategy swaps.
 */


#ifndef ISCHEDULING_ALGORITHM_H
#define ISCHEDULING_ALGORITHM_H

#include "Building.h"
#include "Request.h"

class ISchedulingAlgorithm {
public:
    virtual ~ISchedulingAlgorithm() = default;
    virtual int findNearest(const Request& req, const Building& building) = 0;
};

#endif // ISCHEDULING_ALGORITHM_H
