/*
 * Context for NearestScanScheduler.h
 *
 * REQUIREMENT: 
 *   Implement the concrete nearest-elevator SCAN scheduling algorithm as a strategy subclass.
 * 
 * DESIGN: 
 *   Declare NearestScanScheduler derived from ISchedulingAlgorithm.
 * 
 * IMPLEMENTED: 
 *   Created NearestScanScheduler.h header.
 * 
 * RESULT: 
 *   nearest SCAN strategy interface is declared.
 */


#ifndef NEAREST_SCAN_SCHEDULER_H
#define NEAREST_SCAN_SCHEDULER_H

#include "ISchedulingAlgorithm.h"

class NearestScanScheduler : public ISchedulingAlgorithm {
public:
    int findNearest(const Request& req, const Building& building) override;
};

#endif // NEAREST_SCAN_SCHEDULER_H
