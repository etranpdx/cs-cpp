#include "pool.h"
#include <iostream>

using namespace std;

void Pool::event() {
  cout << "P"; 
}

void Pool::percept() {
  cout << "\nYou hear wind blowing." << endl;
}

int Pool::encounter() {
  cout << "\nYou enter the waters." << endl;
  return 1;
}

void Pool::set_position_x(int x) {
  this->posX = x;
}

void Pool::set_position_y(int y) {
  this->posY = y;
}

int Pool::get_position_x() {
  return this->posX;
}

int Pool::get_position_y() {
  return this->posY;
}
