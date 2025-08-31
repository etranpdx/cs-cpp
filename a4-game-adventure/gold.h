#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include "event.h"

using namespace std;

class Gold : public Event {
private:
    int posX;
    int posY;

public:
    /*********************************************************************
    ** Function: event()
    ** Description: Prints gold object symbol.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The gold object symbol is printed.
    *********************************************************************/
    void event();

    /*********************************************************************
    ** Function: percept()
    ** Description: Prints gold object percept.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The gold object percept is printed.
    *********************************************************************/
    void percept();

    /*********************************************************************
    ** Function: encounter()
    ** Description: Prints gold object encounter message and returns value.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The encounter message is printed and value is returned.
    *********************************************************************/
    int encounter();

    /*********************************************************************
    ** Function: set_position_x()
    ** Description: Sets member variable of the gold object for x coordinate.
    ** Parameters:
    ** posX: integer - representing the x coordinate.
    ** Pre-Conditions: None
    ** Post-Conditions: The member variable for the x coordinate is updated.
    *********************************************************************/
    void set_position_x(int);

    /*********************************************************************
    ** Function: set_position_y()
    ** Description: Sets member variable of the gold object for y coordinate.
    ** Parameters:
    ** posY: integer - representing the y coordinate.
    ** Pre-Conditions: None
    ** Post-Conditions: The member variable for the y coordinate is updated.
    *********************************************************************/
    void set_position_y(int);

    /*********************************************************************
    ** Function: get_position_x()
    ** Description: Returns member variable of the gold object for x coordinate.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The member variable for x coordinate is returned.
    *********************************************************************/
    int get_position_x();

    /*********************************************************************
    ** Function: get_position_y()
    ** Description: Returns member variable of the gold object for y coordinate.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The member variable for y coordinate is returned.
    *********************************************************************/
    int get_position_y();
};

#endif
