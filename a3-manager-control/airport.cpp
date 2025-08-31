#include "airport.h"

using namespace std;

Airport::Airport() {
  name = "";          // Initialize name to an empty string
  num_flights = 0;   // Initialize num_flights to 0
  cap = 0;           // Initialize cap to 0
  f_arr = nullptr;   // Initialize f_arr to nullptr
}

Airport::~Airport() {
  delete[] f_arr;

}

// Mutator functions
void Airport::set_name(const string& airportName) {
    this->name = airportName;
}

void Airport::set_numFlights(const int numFlights) {
    this->num_flights = numFlights;
}

void Airport::set_capacity(const int capacity) {
    this->cap = capacity;
}

void Airport::set_flightArr(Flight* flightArray) {
    // Assuming f_arr is dynamically allocated
    this->f_arr = flightArray;
}

// Accessor functions
string Airport::get_name() const {
    return this->name;
}

int Airport::get_numFlights() const {
    return this->num_flights;
}

int Airport::get_capacity() const {
    return this->cap;
}

Flight* Airport::get_flightArr() const {
    return this->f_arr;
}


void Airport::populate_airport(ifstream& fin) {
    if (!fin.is_open()) {
        cerr << "Error: File is not open." << endl;
        return;
    }
    //read airport data from file
    fin >> this->name >> this->num_flights >> this->cap;
    //allocate memory for flight array
    this->f_arr = new Flight[this->num_flights];

    //populate each flight
    for (int i = 0; i < this->num_flights; ++i) {
        //populate flight data
        this->f_arr[i].populate_flight(fin);
    }
    return; 
}
	

void Airport::add_a_flight(Flight& p) {
        Flight newFlight(p); //copy constructor

        //allocate memory for new temp flight array with increased size
        Flight* tempArr = new Flight[num_flights + 1];
        if (tempArr == nullptr) {
            cerr << "Failed to allocate memory for the new flight array" << endl;
            return;
        }

        //copy existing flights to temp array
        for (int i = 0; i < num_flights; ++i) {
            tempArr[i] = f_arr[i];
        }
  
        //add new flight to end of temp array
        tempArr[num_flights] = newFlight;

        //delete old flight array
        delete[] f_arr;

        //update flight array pointer to point to new temp array
        f_arr = tempArr;

        //increment number of flights
        num_flights++;

        cout << "Flight added successfully to " << name << endl;
    } 


Flight Airport::remove_a_flight(int idx) {
    if (idx < 0 || idx >= num_flights) {
        cerr << "Invalid index. No flight removed." << endl;
        return Flight(); //return default Flight object if index invalid
    }
    Flight removedFlight = f_arr[idx]; // Store the removed flight
    //shift remaining flights to fill gap
    for (int i = idx; i < num_flights - 1; ++i) {
        f_arr[i] = f_arr[i + 1];
    }
    //decrement number of flights
    num_flights--;

    return removedFlight;
}


void Airport::print_airport() {
  cout << endl;
  cout << "**********************************" << endl;
  cout << "******Airport Name: " << get_name() << "******" << endl;
  cout << "Capacity: " << get_capacity() << endl;
  cout << endl;
  cout << "----------------------" << endl;
  
  //iterate over each flight in airport
  for (int i = 0; i < get_numFlights(); ++i) {
      cout << "Flight " << i + 1 << ": " << endl;
      cout << "----------------------" << endl;
      get_flightArr()[i].print_flight();
      cout << "----------------------" << endl;
  }
	return; 
}

