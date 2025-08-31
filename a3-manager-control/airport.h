#ifndef AIRPORT_H
#define AIRPORT_H 

#include <iostream>
#include <string>
#include <fstream>

#include "flight.h"

using namespace std;

class Airport
{
private:
  string name;		//airport name
  int num_flights;	//number of flights
  int cap;			//capacity
  Flight *f_arr;		//flight array

public:
  Airport();
  ~Airport();

  //mutator functions
  void set_name(const string&);
  void set_numFlights(const int);
  void set_capacity(const int);
  void set_flightArr(Flight*);

  //accessor functions
  string get_name() const;
  int get_numFlights() const;
  int get_capacity() const;
  Flight* get_flightArr() const;

/**************************************************
 * Name: populate_airport()
 * Description: Reads airport information from the provided file stream and populates the Airport object.
 * Parameters: ifstream& - reference to the input file stream containing airport information.
 * Pre-conditions: The input file stream is open and valid.
 * Post-conditions: Airport object is populated with data from the input file stream.
 ***********************************************/
  void populate_airport(ifstream& fin);

/**************************************************
 * Name: add_a_flight()
 * Description: Adds a flight to the airport's list of flights.
 * Parameters: Flight& - reference to the Flight object to be added.
 * Pre-conditions: The Flight object is valid and contains necessary flight information.
 * Post-conditions: The Flight object is added to the airport's list of flights.
 ***********************************************/
  void add_a_flight(Flight& p);

/**************************************************
 * Name: remove_a_flight()
 * Description: Removes a flight from the airport's list of flights based on the provided index.
 * Parameters: int - index of the flight to be removed.
 * Pre-conditions: The index is within valid range and corresponds to a flight in the airport's list.
 * Post-conditions: The flight at the specified index is removed from the airport's list of flights.
 ***********************************************/
  Flight remove_a_flight(int idx);

/**************************************************
 * Name: print_airport()
 * Description: Prints the details of all flights in the airport.
 * Parameters: None
 * Pre-conditions: The airport object contains valid flight information.
 * Post-conditions: Flight details are printed to the console.
 ***********************************************/
  void print_airport();


};
#endif