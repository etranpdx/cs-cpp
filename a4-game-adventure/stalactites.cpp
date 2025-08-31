#include "stalactites.h"
#include <iostream>

using namespace std;


void Stalactites::event() {
  cout << "S"; // stalactites signifier
}


void Stalactites::percept() {
  cout << "\nYou hear water dripping." << endl;
}


int Stalactites::encounter() {
// check if stalactites fall on the player
  if (rand() % 2 == 0) {
    cout << "\nStalactites fell on you! Game over." << endl;
    return 0; // indicate encounter resulted in loss
} else {
    // stalactites did not fall on the player
    cout << "\nYou narrowly avoided the falling stalactites." << endl;
    return 1; 
  }
}


void Stalactites::set_position_x(int x) {
  this->posX = x;
}


void Stalactites::set_position_y(int y) {
  this->posY = y;
}


int Stalactites::get_position_x() {
    return this->posX;
}


int Stalactites::get_position_y() {
  return this->posY;
}
