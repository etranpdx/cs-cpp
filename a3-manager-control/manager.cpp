#include "manager.h"

using namespace std;


Manager::Manager() {
    cout << "Manager()" << endl;
    this->num_airports = 0;
    this->a_arr = nullptr;
}

Manager::~Manager() {
    cout << "~Manager()" << endl;
    if (this->a_arr != nullptr) {
        delete[] this->a_arr;
        this->a_arr = nullptr;
    }
}


// Mutator functions
void Manager::set_num_airports(const int numAirports) {
    this->num_airports = numAirports;
}

void Manager::set_airport_array(Airport* airportArray) {
    this->a_arr = airportArray;
}


//accessor functions
int Manager::get_num_airports() const {
    return this->num_airports;
}

Airport* Manager::get_airport_array() const {
    return this->a_arr;
}


void Manager::populate(ifstream& fin) {
    cout << "Populating airports..." << endl;
    if (!fin.is_open()) {
        cerr << "Error: File is not open." << endl;
        return;
    }
    //read number of airports from file
    fin >> this->num_airports;

    //allocate memory for airport array
    this->a_arr = new Airport[this->num_airports];

    //populate each airport
    for (int i = 0; i < this->num_airports; ++i) {
        //populate airport data
        this->a_arr[i].populate_airport(fin);
    }
    return; 
}


int Manager::init(){
  ifstream fin("airport.txt");
  if (!fin.is_open()) {
      cerr << "Error: Failed to open the file." << endl;
      return 0;
  }
  Manager::populate(fin);
  fin.close();
  return 1;
}


void Manager::print_menu(){
  cout << endl;
  cout << "1. View all Airports & Flights info" << endl;
  cout << "2. Check flight info" << endl;
  cout << "3. Add a new flight" << endl;
  cout << "4. Cancel a flight" << endl;
  cout << "5. Take off a flight" << endl;
  cout << "6. Print airport stats" << endl;
  cout << "7. Quit" << endl;

}


int Manager::get_menu_choice() {
int choice;
    do {
        print_menu();
        cout << "Your choice: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 7) {
            cin.clear();
            cin.ignore();
            cerr << "Invalid input. Please enter a number between 1 and 7." << endl;
            choice = 0; //reset choice to loop
        }
    } while (choice < 1 || choice > 7);
    return choice;
}


void Manager::print_all(){
  for (int i = 0; i < num_airports; ++i) {
          cout << "**********************************" << endl;
          a_arr[i].print_airport();
  }
  return; 
}


void Manager::check_flight_control() {
  cout << endl;
      cout << "Enter the flight number: ";
      string flightNum;
      cin >> flightNum;

      bool found = false;
      //iterate each airport and its flights to find inputed flight
      for (int i = 0; i < num_airports; ++i) {
          Flight* flights = a_arr[i].get_flightArr();
          for (int j = 0; j < a_arr[i].get_numFlights(); ++j) {
              if (flights[j].get_flight_num() == flightNum) {
                  found = true;
                  cout << "Flight Found!" << endl;
                  cout << "----------------------" << endl;
                  cout << "Flight #: " << flights[j].get_flight_num() << endl;
                  cout << "Current at: " << flights[j].get_curr_loc() << endl;
                  cout << "Destination: " << flights[j].get_dest() << endl;
                  cout << "Number of Pilots: " << flights[j].get_num_pilots() << endl;
                  string* pilots = flights[j].get_pilots();
                  for (int k = 0; k < flights[j].get_num_pilots(); ++k) {
                      cout << "Pilot " << k + 1 << ": " << pilots[k] << endl;
                  }
                  cout << "----------------------" << endl;
                  break; //exit loop once flight found
              }
          }
      }
      if (!found) {
          cout << "Cannot find your flight." << endl;
      }
   return;
  }

 
void Manager::add_flight_control() {
    //display airport options and get user input
    int airportIndex = select_airport();
    if (airportIndex == -1) {
        return; //invalid selection, exit function
    }
    //check if airport is max capacity
    if (a_arr[airportIndex].get_numFlights() >= a_arr[airportIndex].get_capacity()) {
        cout << "Airport " << a_arr[airportIndex].get_name() << " is at maximum capacity. Cannot add the flight." << endl;
        return;
    }
    //get flight details from user input
    Flight newFlight = get_flight_details(a_arr[airportIndex].get_name());
    //add new flight to selected airport
    a_arr[airportIndex].add_a_flight(newFlight);
  
    //rewrite airport.txt file with updated info
    rewrite_airport_file();
}


int Manager::select_airport() {
    cout << endl;
    cout << "Choose an airport: " << endl;
    for (int i = 0; i < num_airports; ++i) {
        cout << i + 1 << ": Airport " << a_arr[i].get_name() << endl;
    }
    int airportIndex;
    cout << "Enter the airport number: ";
    cin >> airportIndex;
    airportIndex--; //to match array indexing

    //validate airport index
    if (airportIndex < 0 || airportIndex >= num_airports) {
        cerr << "Invalid airport number." << endl;
        return -1;
    }

    return airportIndex;
}


int Manager::select_flight_index(const Airport& airport) {
    int flightIndex;
    cout << "Choose a flight: ";
    cin >> flightIndex;
    flightIndex--; //to match array indexing

    //validate flight index
    if (flightIndex < 0 || flightIndex >= airport.get_numFlights()) {
        cerr << "Invalid flight number." << endl;
        return -1;
    }
    return flightIndex;
}


Flight Manager::get_flight_details(const string& airportName) {
    string flightNum, dest;
    int numPilots;

    cout << "Enter flight no.: ";
    cin >> flightNum;
    cout << "Enter destination: ";
    cin >> dest;
    cout << "Number of pilots: ";
    cin >> numPilots;

    //create array to store pilot names
    string* pilots = new string[numPilots];
    for (int i = 0; i < numPilots; ++i) {
        cout << "Enter name for pilot " << i + 1 << ": ";
        cin >> pilots[i];
    }

    //create the new Flight object
    Flight newFlight;
    newFlight.set_flight_num(flightNum);
    newFlight.set_curr_loc(airportName);
    newFlight.set_dest(dest);
    newFlight.set_num_pilots(numPilots);
    newFlight.set_pilots(pilots);

    //free memory allocated for pilots array
    delete[] pilots;

    return newFlight;
}


void Manager::rewrite_airport_file() {
    ofstream fout("airport.txt");
    if (fout.is_open()) {
        fout << num_airports << endl; 
        for (int i = 0; i < num_airports; ++i) {
            fout << a_arr[i].get_name() << ' ' << a_arr[i].get_numFlights() << ' ' << a_arr[i].get_capacity() << endl;
            Flight* flights = a_arr[i].get_flightArr();
            for (int j = 0; j < a_arr[i].get_numFlights(); ++j) {
                fout << flights[j].get_flight_num() << ' ' << flights[j].get_curr_loc() << ' ' << flights[j].get_dest() << ' ' << flights[j].get_num_pilots();
                string* pilots = flights[j].get_pilots();
                for (int k = 0; k < flights[j].get_num_pilots(); ++k) {
                    fout << ' ' << pilots[k];
                }
                fout << endl;
            }
        }
        fout.close();
    } else {
        cerr << "Failed to open airport.txt for writing." << endl;
    }
}


void Manager::cancel_flight_control() {
    //display airport options and get user input
    int airportIndex = select_airport();
    if (airportIndex == -1) {
        return; //invalid selection, exit function
    }
  //display flights in selected airport
  a_arr[airportIndex].print_airport();

  int flightIndex = select_flight_index(a_arr[airportIndex]);
  if (flightIndex == -1) {
      return; //invalid selection, exit function
  }
    //remove selected flight from airport
    Flight removedFlight = a_arr[airportIndex].remove_a_flight(flightIndex);
    cout << endl;
    cout << "The following flight has been cancelled:" << endl;
    removedFlight.print_flight(); //print details of removed flight

    //rewrite airport.txt file with updated flight info
    rewrite_airport_file();
}


void Manager::take_off_control() {
    int airportIndex = select_airport();
    if (airportIndex == -1) {
        return; //invalid selection, exit function
    }
    //display flights in selected airport
    a_arr[airportIndex].print_airport();

    //get user input for flight take off
    int flightIndex = select_flight_index(a_arr[airportIndex]);
    if (flightIndex == -1) {
        return; //invalid selection, exit function
    }
    //retrieve selected flight
    Flight selectedFlight = a_arr[airportIndex].get_flightArr()[flightIndex];

    //get destination airport name from selected flight
    string destinationAirportName = selectedFlight.get_dest();

    //iterate for destination airport
    int destinationIndex = -1;
    for (int i = 0; i < num_airports; ++i) {
        if (a_arr[i].get_name() == destinationAirportName) {
            destinationIndex = i;
            break;
        }
    }
    //check if destination airport exists
    if (destinationIndex == -1) {
        cerr << "Destination airport not found." << endl;
        return;
    }
    //check if destination airport has enough capacity for new flight
    if (a_arr[destinationIndex].get_numFlights() >= a_arr[destinationIndex].get_capacity()) {
        cerr << "Destination airport " << a_arr[destinationIndex].get_name() << " is at maximum capacity." << endl;
        return;
    }
    //remove selected flight from source airport
    a_arr[airportIndex].remove_a_flight(flightIndex);
    //set current location of flight to destination airport
    selectedFlight.set_curr_loc(destinationAirportName);
    //add selected flight to destination airport
    a_arr[destinationIndex].add_a_flight(selectedFlight);
    //rewrite airport.txt file with updated info
    rewrite_airport_file();

    cout << endl;
    cout << "The following flight has been taken off:" << endl;
    cout << "----------------------" << endl;
    selectedFlight.print_flight();
    cout << "----------------------" << endl;

    return;
}


void Manager::stats_control() {
  cout << endl;
  cout << "Airport Stats:" << endl;
  for (int i = 0; i < num_airports; ++i) {
      cout << "Airport " << a_arr[i].get_name() << endl;
      cout << "Capacity: " << a_arr[i].get_capacity() << endl;

      int numListedFlights = 0;
      string airportName = a_arr[i].get_name();
      for (int j = 0; j < num_airports; ++j) {
          if (j != i) {
              Flight* flights = a_arr[j].get_flightArr();
              for (int k = 0; k < a_arr[j].get_numFlights(); ++k) {
                  if (flights[k].get_dest() == airportName) {
                      numListedFlights++;
                  }
              }
          }
      }
      cout << "Listed as destination: " << numListedFlights << " flights" << endl;
      cout << endl;
  }
  return; 
}


void Manager::run() {
  cout << endl;
  cout << "Welcome to Flight Manager!!" << endl;
  if (Manager::init() != 1)
    return;

  int choice = -1;
  while (choice != 7)
  {
    choice = Manager::get_menu_choice();

    //print all
    if (choice == 1) 
      Manager::print_all();

    //flight info
    else if (choice == 2){
      Manager::check_flight_control();
    }
    //add a new flight
    else if (choice == 3) {
      Manager::add_flight_control();
    }
    //cancel a flight
    else if (choice == 4) {
      Manager::cancel_flight_control();
    }
    //take off a flight
    if (choice == 5){
      Manager::take_off_control();
    }
    //airport stats
    else if (choice == 6) {
      Manager::stats_control();
    }
  }

  cout << "Bye!" << endl << endl;

  return;
}