/*
 * STAR Context for Display.h
 *
 * SITUATION: 
 *   We need to display the current state of elevators and floors in a structured format in the console.
 * 
 * TASK: 
 *   Define a Display class containing methods to print elevator status and building floor views.
 * 
 * ACTION: 
 *   Declared static helper methods that accept Building reference to render status outputs.
 * 
 * RESULT: 
 *   A dedicated presentation interface is available, separating UI display from logic.
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "Building.h"

class Display {
public:
    static void showStatus(const Building& building);
};

#endif // DISPLAY_H
