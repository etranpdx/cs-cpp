#ifndef FLIGHT_H
#define FLIGHT_H 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight
{
private: 
  string flight_num;		//flight number
  string curr_loc;		//current airport
  string dest;			//destination 
  int num_pilots;			//number of pilots
  string* pilots;			//pilot array

public:
  Flight();           //default constructor
  Flight (int size) ; //non default constructor
  ~Flight();          //destructor
  Flight& operator=(const Flight& obj); // assignment operator overload
  Flight (const Flight& obj);

  //mutator
  void set_flight_num(const string&);
  void set_curr_loc(const string&);
  void set_dest(const string&);
  void set_num_pilots(const int);
  void set_pilots(string*);

  //accessor
  string get_flight_num() const;
  string get_curr_loc() const;
  string get_dest() const;
  int get_num_pilots() const;
  string* get_pilots() const;

/**************************************************
 * Name: populate_flight()
 * Description: Reads flight information from the provided file stream and populates the Flight object.
 * Parameters: ifstream& - reference to the input file stream containing flight information.
 * Pre-conditions: The input file stream is open and valid.
 * Post-conditions: Flight object is populated with data from the input file stream.
 ***********************************************/
  void populate_flight(ifstream&);

/**************************************************
 * Name: print_flight()
 * Description: Prints the details of the flight to the console.
 * Parameters: None
 * Pre-conditions: The Flight object contains valid flight information.
 * Post-conditions: Flight details are printed to the console.
 ***********************************************/
  void print_flight();





};

#endif
