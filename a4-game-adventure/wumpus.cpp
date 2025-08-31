#include "wumpus.h"
#include <iostream>

using namespace std;

void Wumpus::event() {
  cout << "W";
}

void Wumpus::percept() {
  cout << "\nYou smell a terrible stench." << endl;
}

int Wumpus::encounter() {
  cout << "\nYou've been eaten by the Wumpus! Game over." << endl;
  return 0;
}

void Wumpus::set_position_x(int x) {
  this->posX = x;
}

void Wumpus::set_position_y(int y) {
  this->posY = y;
}

int Wumpus::get_position_x() {
  return this->posX;
}

int Wumpus::get_position_y() {
  return this->posY;
}