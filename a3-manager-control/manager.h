#ifndef MANAGER_H
#define MANAGER_H 

#include "airport.h"
#include <iostream>
#include <fstream>

using namespace std;

class Manager
{
private:
  int num_airports;	//number of airports
  Airport* a_arr;		//airport array


public:
  Manager();
  ~Manager();

  //mutator functions
  void set_num_airports(const int);
  void set_airport_array(Airport*);

  //accessor functions
  int get_num_airports() const;
  Airport* get_airport_array() const;


/**************************************************
 * Name: populate()
 * Description: Populates data from the provided input file stream.
 * Parameters: ifstream& - reference to the input file stream.
 * Pre-conditions: The input file stream is open and valid.
 * Post-conditions: Data is populated from the input file stream.
 ***********************************************/
  void populate(ifstream& fin);

/**************************************************
 * Name: init()
 * Description: Initializes the flight manager.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Flight manager is initialized.
 ***********************************************/
  int init();

/**************************************************
 * Name: print_menu()
 * Description: Prints the menu options to the console.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Menu options are printed to the console.
 ***********************************************/
  void print_menu();

/**************************************************
 * Name: get_menu_choice()
 * Description: Gets the user's menu choice.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: User's menu choice is obtained.
 * Returns: int - the user's menu choice.
 ***********************************************/
  int get_menu_choice();

/**************************************************
 * Name: print_all()
 * Description: Prints all flights and airport details.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: All flights and airport details are printed to the console.
 ***********************************************/
  void print_all();

/**************************************************
 * Name: check_flight_control()
 * Description: Controls checking flight details.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Flight details are checked and printed to the console.
 ***********************************************/
  void check_flight_control();

/**************************************************
 * Name: add_flight_control()
 * Description: Controls adding a new flight.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: A new flight is added.
 ***********************************************/
  void add_flight_control();

/**************************************************
 * Name: cancel_flight_control()
 * Description: Controls cancelling a flight.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: A flight is cancelled.
 ***********************************************/
  void cancel_flight_control();

/**************************************************
 * Name: take_off_control()
 * Description: Controls taking off a flight.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: A flight is taken off.
 ***********************************************/
  void take_off_control();

/**************************************************
 * Name: stats_control()
 * Description: Controls checking statistics.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Statistics are checked and printed to the console.
 ***********************************************/
  void stats_control();

/**************************************************
 * Name: select_airport()
 * Description: Selects an airport.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: An airport is selected.
 * Returns: int - the selected airport index.
 ***********************************************/
  int select_airport();

/**************************************************
 * Name: select_flight_index()
 * Description: Selects a flight index.
 * Parameters: const Airport& - reference to the Airport object.
 * Pre-conditions: None
 * Post-conditions: A flight index is selected.
 * Returns: int - the selected flight index.
 ***********************************************/
  int select_flight_index(const Airport& airport);

/**************************************************
 * Name: get_flight_details()
 * Description: Gets details of a flight.
 * Parameters: const string& - reference to the airport name.
 * Pre-conditions: None
 * Post-conditions: Details of a flight are obtained.
 * Returns: Flight - the flight details.
 ***********************************************/
  Flight get_flight_details(const string& airportName);

/**************************************************
 * Name: rewrite_airport_file()
 * Description: Rewrites airport information to the file.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Airport information is rewritten to the file.
 ***********************************************/
  void rewrite_airport_file();

/**************************************************
 * Name: run()
 * Description: Runs the flight manager.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Flight manager is executed.
 ***********************************************/
  void run();

};
#endif