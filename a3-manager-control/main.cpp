/******************************************************
** Program: main.cpp
** Author: Eric Tran
** Date: 2/27/2024
** Description: This program is going to simulate some 
** of the basic functionalities of air traffic control 
** systems. The program will allow the user, which is 
** the flight manager, to interact with multiple flights 
** across multiple airports.
** Input: Input data from user, airport.txt
** Output: Output data to console, airport.txt
******************************************************/
#include <iostream>
#include "manager.h"

using namespace std;

int main()
{
  
	Manager m;
	m.run();
	return 0;
  

}
