#include "flight.h"

using namespace std;

Flight::Flight() {
  this->flight_num = "";
  this->curr_loc = "";
  this->dest = "";
  this->num_pilots = 0;
  this->pilots = nullptr;
}

Flight::~Flight() {
   delete[] pilots;
}

// Copy constructor
Flight::Flight(const Flight &other) {
    // Initialize member variables
    this->flight_num = other.flight_num;
    this->curr_loc = other.curr_loc;
    this->dest = other.dest;
    this->num_pilots = other.num_pilots;

    // Allocate memory for pilots array
    if (this->num_pilots > 0) {
        this->pilots = new string[this->num_pilots];

        // Copy pilots data from other object
        for (int i = 0; i < this->num_pilots; ++i) {
            this->pilots[i] = other.pilots[i];
        }
    } else {
        this->pilots = nullptr;
    }
}

// Assignment operator overload
Flight& Flight::operator=(const Flight &other) {
    if (this != &other) {
        // Deallocate existing memory for pilots array
        delete[] this->pilots;

        // Copy flight data from other object
        this->flight_num = other.flight_num;
        this->curr_loc = other.curr_loc;
        this->dest = other.dest;
        this->num_pilots = other.num_pilots;

        // Allocate memory for pilots array
        if (this->num_pilots > 0) {
            this->pilots = new string[this->num_pilots];

            // Copy pilots data from other object
            for (int i = 0; i < this->num_pilots; ++i) {
                this->pilots[i] = other.pilots[i];
            }
        } else {
            this->pilots = nullptr;
        }
    }
    return *this;
}


// Mutator functions
void Flight::set_flight_num(const string& num) {
    this->flight_num = num;
}

void Flight::set_curr_loc(const string& loc) {
    this->curr_loc = loc;
}

void Flight::set_dest(const string& destination) {
    this->dest = destination;
}

void Flight::set_num_pilots(const int num) {
    this->num_pilots = num;
}

void Flight::set_pilots(string* pilots) {
    //free existing memory if pilots is not nullptr
    if (this->pilots != nullptr) {
        delete[] this->pilots;
    }

    //allocate memory for new pilots array
    this->pilots = new string[num_pilots];

    //copy pilot names from input array to object's pilots array
    for (int i = 0; i < num_pilots; ++i) {
        this->pilots[i] = pilots[i];
    }
}


// Accessor functions
string Flight::get_flight_num() const {
    return this->flight_num;
}

string Flight::get_curr_loc() const {
    return this->curr_loc;
}

string Flight::get_dest() const {
    return this->dest;
}

int Flight::get_num_pilots() const {
    return this->num_pilots;
}

string* Flight::get_pilots() const {
    return this->pilots;
}



void Flight::populate_flight(ifstream& fin) {
    if (!fin.is_open()) {
        cerr << "Error: File is not open." << endl;
        return;
    }

    //read flight data from file
    fin >> this->flight_num >> this->curr_loc >> this->dest >> this->num_pilots;

    //allocate memory for pilots array
    this->pilots = new string[this->num_pilots];

    //populate pilots' names
    for (int i = 0; i < this->num_pilots; ++i) {
        fin >> this->pilots[i];
    }

    cout << "Populated flight: " << this->flight_num << endl;
    cout << "Current location: " << this->curr_loc << endl;
    cout << "Destination: " << this->dest << endl;
    cout << "Number of pilots: " << this->num_pilots << endl;
    cout << "Pilots: ";
    for (int i = 0; i < this->num_pilots; ++i) {
        cout << this->pilots[i] << " ";
    }
    cout << endl;
}



void Flight::print_flight() {
  cout << "Flight #: " << flight_num << endl;
  cout << "Current at: " << curr_loc << endl;
  cout << "Destination: " << dest << endl;
  cout << "Number of Pilots: " << num_pilots << endl;
  cout << "Pilots: ";
  for (int i = 0; i < num_pilots; ++i) {
    cout << pilots[i];
      if (i < num_pilots - 1) {
        cout << ", ";
    }
}
  cout << endl;
	return;
}




