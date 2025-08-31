# A03 — Flight Manager (C++)

Menu-driven air-traffic control simulation for multiple airports. Loads initial data from file, then lets the user view airports/flights, look up a flight, add/cancel flights, move a flight to its destination (takeoff), and print per-airport statistics. All operations validate input and enforce airport capacity.

## TL;DR
- OOP design with `Flight`, `Airport`, and `Manager` classes (composition & encapsulation)
- File I/O to populate airports/flights; in-memory updates with capacity checks
- Robust input validation (menu choices, airport selection, flight numbers, pilot counts)
- Operations: view all, search flight, add flight, cancel flight, takeoff (move), and stats

## Skills Demonstrated
C++ basics • classes/constructors/destructors • file I/O (`ifstream`) • search & validation • arrays/vectors & iteration • formatted console I/O

## Example Output:  
Welcome to Flight Manager!!  
1. View all Airports & Flights info  
2. Check flight info  
3. Add a new flight  
4. Cancel a flight  
5. Take off a flight  
6. Print airport stats  
7. Quit  
Your choice: 1  
    
  
******Airport Name: A******  
Capacity: 4  
Flight 1:  
  
Flight #: A123  
Current at: A  
Destination: B  
Pilot 1: P1  
Pilot 2: P2  
  
... (other airports/flights)  
  
Your choice: 2  
Enter the flight number: C000  
Flight Found!  
  
Flight #: C000  
Current at: C  
Destination: B  
Pilot 1: P16  
  
