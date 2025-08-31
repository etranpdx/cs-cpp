#ifndef POOL_H
#define POOL_H

#include "event.h"

class Pool : public Event {
private:
    int posX;
    int posY;

public:
    /*********************************************************************
    ** Function: event()
    ** Description: Prints pool object symbol.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The pool object symbol is printed.
    *********************************************************************/
    void event();

    /*********************************************************************
    ** Function: percept()
    ** Description: Prints pool object percept.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The pool object percept is printed.
    *********************************************************************/
    void percept();

    /*********************************************************************
    ** Function: encounter()
    ** Description: Prints pool object encounter message and returns value.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The encounter message is printed and value is returned.
    *********************************************************************/
    int encounter();

    /*********************************************************************
    ** Function: set_position_x()
    ** Description: Sets member variable of the pool object for x coordinate.
    ** Parameters:
    ** x: integer - representing the x coordinate.
    ** Pre-Conditions: None
    ** Post-Conditions: The member variable for the x coordinate is updated.
    *********************************************************************/
    void set_position_x(int x);

    /*********************************************************************
    ** Function: set_position_y()
    ** Description: Sets member variable of the pool object for y coordinate.
    ** Parameters:
    ** y: integer - representing the y coordinate.
    ** Pre-Conditions: None
    ** Post-Conditions: The member variable for the y coordinate is updated.
    *********************************************************************/
    void set_position_y(int y);

    /*********************************************************************
    ** Function: get_position_x()
    ** Description: Returns member variable of the pool object for x coordinate.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The member variable for x coordinate is returned.
    *********************************************************************/
    int get_position_x();

    /*********************************************************************
    ** Function: get_position_y()
    ** Description: Returns member variable of the pool object for y coordinate.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The member variable for y coordinate is returned.
    *********************************************************************/
    int get_position_y();
};

#endif
