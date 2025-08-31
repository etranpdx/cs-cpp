#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <iostream>

using namespace std;

class Room {
private:
    Event *event;

public:
    /*********************************************************************
    ** Function: Room()
    ** Description: The constructor for Room class and initializes event pointer to null.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The event pointer is set null.
    *********************************************************************/
    Room();

    /*********************************************************************
    ** Function: ~Room()
    ** Description: The destructor for Room class and deallocates event pointer.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The event pointer is deallocated.
    *********************************************************************/
    ~Room();

    /*********************************************************************
    ** Function: get_event_pointer()
    ** Description: Getter function for event pointer.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The event pointer is returned.
    *********************************************************************/
    Event* get_event();

    /*********************************************************************
    ** Function: set_event_pointer()
    ** Description: Setter function for the event pointer. It deletes current 
    **              event pointer and updates it.
    ** Parameters:
    ** event: Pointer to Event object
    ** Pre-Conditions: None
    ** Post-Conditions: The event pointer is updated with the passed pointer.
    *********************************************************************/
    void set_event(Event*);
};

#endif