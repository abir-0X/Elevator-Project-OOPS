/*
 * Context for Exceptions.h
 *
 * REQUIREMENT: 
 *   Need custom exceptions to handle invalid inputs or system states during the simulation.
 * 
 * DESIGN: 
 *   Define InvalidFloorException and InvalidElevatorException inheriting from standard library exceptions.
 * 
 * IMPLEMENTED: 
 *   Created Exceptions.h with custom exception class structures.
 * 
 * RESULT: 
 *   Defensive programming checks can throw clear, specialized errors that main.cpp can handle.
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidFloorException : public std::invalid_argument {
public:
    explicit InvalidFloorException(const std::string& msg) : std::invalid_argument(msg) {}
};

class InvalidElevatorException : public std::invalid_argument {
public:
    explicit InvalidElevatorException(const std::string& msg) : std::invalid_argument(msg) {}
};

#endif // EXCEPTIONS_H
