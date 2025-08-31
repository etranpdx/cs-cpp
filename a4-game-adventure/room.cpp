#include "room.h"

Room::Room() {
  this->event = nullptr;
}

Room::~Room() {
  delete this->event; 
}

Event* Room::get_event() {
  return this->event;
}

void Room::set_event(Event* event) {
  delete this->event;
  this->event = event;
}