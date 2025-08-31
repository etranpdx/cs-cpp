#include "game.h"
#include <iostream>


using namespace std;


// constructor for Game class, initializes game state variables
Game::Game() {
  srand(time(NULL)); // seed random number
  hasGold = false; 
  killedWumpus = false; 
  underwater = false; 
}

// destructor for Game class, deallocates memory eventArr
Game::~Game() {
  for (int i = 0; i < eventArr.size(); i++) {
    delete eventArr[i]; // delete each event
    eventArr[i] = nullptr; // set pointer to null
  }
}


void Game::set_up(int s){
  //set up the game
  this->side = s; // set the side length of the board
  this->num_arrows = 3; // start with 3 arrows

  // initialize board with NULL pointers
  for (int i = 0; i < s; i++) {
    vector<Room*> temp(s, NULL);
    this->board.push_back(temp);
  }

  populate_event();
  populate_board();
}


void Game::populate_event() {
  // create events and add to eventArr
  for (int i = 0; i < 6; i++) {
    Room *room = new Room;
    this->eventArr.push_back(room);
  }

  // assign each event to specific
  for (int i = 0; i < 6; i++) {
    Room *room = this->eventArr[i];
    Event *event = room->get_event();
    delete event;
    if (i == 0) {
      event = new Wumpus; // create a Wumpus event
    } else if (i == 1) {
      event = new Gold; // create a Gold event
    } else if (i % 2 == 0) {
      event = new Pool; // create a Pool event
    } else {
      event = new Stalactites; // create a Stalactites event
    }
    room->set_event(event); 
  }
}


void Game::populate_board() {
  int x, y;
  // place events from eventArr to board
  for (int i = 0; i < 6; i++) {
    do {
      x = rand() % board[0].size();
      y = rand() % board[0].size();
    } while (board[x][y] != NULL);

    board[x][y] = eventArr[i]; // place event on board
    this->board[x][y]->get_event()->set_position_x(x); // set event x position
    this->board[x][y]->get_event()->set_position_y(y); // set event y position
  }
  // place player on board
  do {
    x = rand() % board[0].size();
    y = rand() % board[0].size();
  } while (board[x][y] != NULL);
  this->playerX = x; // set player position
  this->playerY = y; 
  this->orgX = x; // set original position
  this->orgY = y; 
}


bool Game::valid_win(int message) const {
  // check if player has gold and has returned to starting position
  if (!this->hasGold || (this->playerX != orgX || this->playerY != orgY) && message != 0) {
    return false;
  }
  return true;
}


void Game::display_game() const {
    cout << endl << endl;
    cout << "Arrows remaining: " << this->num_arrows << endl;
    cout << "Oxygen Level: " << this->oxygenLevel << endl;
    string line = "";
    for (int i = 0; i < this->side; ++i)
        line += "-----";
    cout << line << endl;

    // loop and display room content
    for (int i = 0; i < this->side; ++i) {
        for (int j = 0; j < this->side; ++j) {
            // display player symbol
            if (i == playerX && j == playerY) {
                cout << "*";
            } else if (i == orgX && j == orgY && debug_view == true) {
                cout << "~"; 
            } else {
                cout << " ";
            }
            // display event symbol
            if (this->board[i][j] == nullptr) {
                cout << "  ||";
            } else {
                if (debug_view == true) {
                  this->board[i][j]->get_event()->event();
              } else {
                    cout << " ";
                }
            cout << " ||";
            } 

        }
        cout << endl << line << endl;
    }
}

// displays percepts
void Game::validPercepts() const {
  for (int i = 0; i < this->board.size(); i++) {
    for (int j = 0; j < this->board[0].size(); j++) {
      // check if room adjacent to player and contain event
      if (adjacent(i, j) && board[i][j] != NULL) {
        this->board[i][j]->get_event()->percept();
      }
    }
  }
  cout << endl;
}


bool Game::adjacent(const int i, const int j) const {
    int dx = abs(playerX - i);
    int dy = abs(playerY - j);
    return (dx == 1 && dy == 0) || (dx == 0 && dy == 1);
}


string Game::get_dir(){
  string dir;
  cout << "\nFire an arrow...." << endl;
  cout << "w-up" << endl;
  cout << "a-left" << endl;
  cout << "s-down" << endl;
  cout << "d-right" << endl;
  cout << "Enter direction: " << endl;
  cin >> dir;
  // validate direction input
  while (dir != "w" && dir != "a" && dir != "s" && dir != "d") {
    cout << "\nInvalid. Enter a valid direction: ";
    cin >> dir;
  }
  return dir;
}


bool Game::valid_wumpus(const string dir) {
  int wumX = this->eventArr[0]->get_event()->get_position_x();
  int wumY = this->eventArr[0]->get_event()->get_position_y();

  int dx = 0, dy = 0;
  // calculate change in x and y
  if (dir == "w") dx = -1;
  else if (dir == "a") dy = -1;
  else if (dir == "s") dx = 1;
  else if (dir == "d") dy = 1;

  // check if Wumpus is hit
  for (int i = 1; i < 4; ++i) {
    int newX = playerX + (i * dx);
    int newY = playerY + (i * dy);

    if (newX == wumX && newY == wumY) {
      kill_wumpus(wumX, wumY);
      return true;
    }
  }
  move_wumpus(wumX, wumY);
  return false;
}


void Game::kill_wumpus(const int wumX, const int wumY) {
  cout << "\nYou killed Wumpus with your arrow!" << endl;
  this->board[wumX][wumY] = NULL; // remove Wumpus from board
  this->killedWumpus = true; // set killedWumpus flag to true
}


void Game::move_wumpus(const int wumX, const int wumY) {
  int x, y;
  cout << "\nYou missed! Wumpus has awoken and might've "
          "move."
       << endl;
  int randNum = rand() % 4;
  if (randNum > 0) {
    board[wumX][wumY] = NULL; // remove Wumpus from current position
    do {
      x = rand() % board[0].size();
      y = rand() % board[0].size();
    } while (board[x][y] != NULL || (x == wumX && y == wumY));

    board[x][y] = eventArr[0]; // place Wumpus in new position
    this->board[x][y]->get_event()->set_position_x(x); // set Wumpus position
    this->board[x][y]->get_event()->set_position_y(y); 
  }
}


void Game::fire_arrow(){
  string dir = get_dir(); // get arrow direction from user
  this->killedWumpus = valid_wumpus(dir); // check if Wumpus is hit
  return;
}


int Game::handle_player_input() {
    string direction;
    int results = -1;
    int message = -1;

    direction = get_input(num_arrows); // get input from player

    // move player or fire arrow based on input
    if (direction != "f") {
        results = move(direction); 
        if (results == 0) {
          message = 0;
          return message;
        }
    } else {
        if (killedWumpus) {
            cout << "\nThe Wumpus is already dead." << endl;
        } else if (underwater) {
            cout << "\nCan't shoot arrows underwater" << endl;
        } else {
            fire_arrow(); // fire arrow
            num_arrows--; // decrement arrow count
        }
    }
  return message;
}


string Game::get_input(int a) {
  string direction;

  cout << endl << endl << "Player move..." << endl << endl;
  cout << "w-up" << endl;
  cout << "a-left" << endl;
  cout << "s-down" << endl;
  cout << "d-right" << endl;
  cout << "f-fire an arrow" << endl;
  cout << "Enter input: ";
  cin >> direction; // get input from player
  cin.ignore(256, '\n'); // ignore remaining characters in input buffer

  // validate input
  while (true) {
      if ((direction == "w" || direction == "a" || direction == "s" || direction == "d") |
          (direction == "f" && a > 0 && !this->killedWumpus && !underwater)) {
          int newX = playerX;
          int newY = playerY;

          if (direction == "w") newX--;
          else if (direction == "a") newY--;
          else if (direction == "s") newX++;
          else if (direction == "d") newY++;
          if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()) {
              return direction;
          } else {
              cout << "You cannot move outside the boundaries." << endl;
          }
      } else {
          cout << "Enter a valid direction (w a s d) or f: ";
      }
      cin >> direction; 
      cin.ignore(256, '\n');
  }
    return direction;
}


int Game::move(const string d) {
 int results = -1;

    movePlayer(d); // move player
    handlePool(); // handle effects of pool event

    if (underwater) {
        oxygenLevel--; // decrement oxygen level
        if (oxygenLevel <= 0) {
            cout << "\nYou suffocated and died!\n"; // player runs out of oxygen
            results = 0;
        }
    }
    return results;
}


void Game::movePlayer(const string d) {  // move player in specified direction
    if (d == "w") {
        this->playerX--;
    } else if (d == "a") {
        this->playerY--;
    } else if (d == "s") {
        this->playerX++;
    } else if (d == "d") {
        this->playerY++;
    }
}


void Game::handlePool() {
    if (board[playerX][playerY] != NULL && dynamic_cast<Pool*>(board[playerX][playerY]->get_event())) {
        underwater = !underwater; // toggle underwater flag
        if (underwater) {
            cout << "\nYou dive into the pool.\n"; // player dives into pool
            debug_view = true; // enable debug view
        } else {
            cout << "\nYou resurface from the pool.\n"; // player resurfaces from pool
            oxygenLevel = 2 * side; // reset oxygen level
            debug_view = initial_debug_mode; // restore debug mode
        }
    }
}


int Game::play_encounters() {
  int message = -1;
  if (!underwater) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] != nullptr && i == playerX && j == playerY) {
          message = board[i][j]->get_event()->encounter(); // handle encounter with event
          if (message == 2 && !this->hasGold) {
            this->hasGold = true;
            board[i][j] = nullptr; // remove gold from board
          }
        }
      }
    }
  }
    return message;
}


void Game::valid_end(const int message) const {  // displays the game result
    display_game(); // display game state

    if (message != 0) {
        cout << "\nCongratulations, you have escaped with the gold and won the game!\n" << endl;
    }
}


void Game::play_game(int s, bool d){
    Game::set_up(s); // set up game
    this->initial_debug_mode = d; // set initial debug mode
    this->debug_view = initial_debug_mode; // set debug view
    this->oxygenLevel = 2 * side; // set initial oxygen level
    int message = -1;

    // main game loop
    while (!valid_win(message) && message != 0) {
      display_game(); // display game grid
      validPercepts();
      message = handle_player_input(); // handle player input
      if (message != 0) {
        message = play_encounters(); // handle encounters
      }
    }

  valid_end(message); // display game end message
  return;
}
