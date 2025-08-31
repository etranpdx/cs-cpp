#include "gold.h"
#include <iostream>

using namespace std;

void Gold::event() {
  cout << "G"; // gold signifier
}

void Gold::percept() {
  cout << "\nYou see a glimmer nearby." << endl; // gold percept
}

int Gold::encounter() {
  cout << "\nYou have grabbed the gold!";  // gold encounter
  return 2;
}

void Gold::set_position_x(int x) {
  this->posX = x;
}

void Gold::set_position_y(int y) {
  this->posY = y;
}

int Gold::get_position_x() {
  return this->posX;
}

int Gold::get_position_y() {
  return this->posY;
}