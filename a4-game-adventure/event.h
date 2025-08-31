#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event {
protected:
    int posX;
    int posY;

public:
    /*********************************************************************
    ** Function: event()
    ** Description: Prints the event message.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    *********************************************************************/
    virtual void event() = 0;

    /*********************************************************************
    ** Function: percept()
    ** Description: Prints the percept message.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    *********************************************************************/
    virtual void percept() = 0;

    /*********************************************************************
    ** Function: encounter()
    ** Description: Prints the encounter message and returns value.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    *********************************************************************/
    virtual int encounter() = 0;

    /*********************************************************************
    ** Function: set_position_x()
    ** Description: Sets the x position.
    ** Parameters:
    ** posX: integer - represents the x position
    ** Pre-Conditions: None
    ** Post-Conditions: The x position is set.
    *********************************************************************/
    virtual void set_position_x(int) = 0;

    /*********************************************************************
    ** Function: set_position_y()
    ** Description: Sets the y position.
    ** Parameters:
    ** posY: integer - represents the y position
    ** Pre-Conditions: None
    ** Post-Conditions: The y position is set.
    *********************************************************************/
    virtual void set_position_y(int) = 0;

    /*********************************************************************
    ** Function: get_position_x()
    ** Description: Gets the x position.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    ** Returns: Integer representing the x position.
    *********************************************************************/
    virtual int get_position_x() = 0;

    /*********************************************************************
    ** Function: get_position_y()
    ** Description: Gets the y position.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    ** Returns: Integer representing the y position.
    *********************************************************************/
    virtual int get_position_y() = 0;

    virtual ~Event() {}

};

#endif