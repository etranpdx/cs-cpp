#ifndef GAME_H
#define GAME_H 

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "room.h"
#include "wumpus.h"
#include "gold.h"
#include "pool.h"
#include "stalactites.h"

using namespace std;

//Game interface 
class Game
{
private:
  int playerX;
  int playerY;
  int orgX;
  int orgY;
  vector<Room*> eventArr;
  vector< vector<Room*> > board;
  bool hasGold;
  bool killedWumpus;
	int side; 				//side of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
  bool initial_debug_mode;
  bool underwater;
  int oxygenLevel;

public:
  /*********************************************************************
  ** Function: Game()
  ** Description: Constructor for the Game class.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Game object is initialized.
  *********************************************************************/
	Game();

  /*********************************************************************
  ** Function: ~Game()
  ** Description: Destructor for the Game class.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Memory is deallocated.
  *********************************************************************/
	~Game();

  /*********************************************************************
  ** Function: set_up(int)
  ** Description: Sets up the game grid and events.
  ** Parameters:
  ** s: integer - size of the grid.
  ** Pre-Conditions: None
  ** Post-Conditions: Game grid and events are initialized.
  *********************************************************************/
	void set_up(int);

  /*********************************************************************
  ** Function: display_game() const
  ** Description: Displays the game grid.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Game grid is printed to the console.
  *********************************************************************/
	void display_game() const;

  /*********************************************************************
  ** Function: valid_win(int) const
  ** Description: Checks if the player has won the game.
  ** Parameters:
  ** message: integer - message indicating specific win condition.
  ** Pre-Conditions: None
  ** Post-Conditions: Returns true if the player has won, false otherwise.
  *********************************************************************/
	bool valid_win(int) const;

  /*********************************************************************
  ** Function: get_dir()
  ** Description: Gets the direction in which the player wants to fire the arrow.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Returns the direction chosen by the player.
  *********************************************************************/
	string get_dir();

  /*********************************************************************
  ** Function: fire_arrow()
  ** Description: Fires an arrow in the direction chosen by the player and checks if the arrow hits the Wumpus.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: The arrow is fired, and the result of hitting the Wumpus is determined.
  *********************************************************************/
	void fire_arrow();

  /*********************************************************************
  ** Function: handle_player_input()
  ** Description: Handles player input for movement and actions.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Player input is processed.
  *********************************************************************/
  int handle_player_input();

  /*********************************************************************
  ** Function: get_input(int)
  ** Description: Gets player input for movement or actions.
  ** Parameters:
  ** a: integer - number of arrows the player has.
  ** Pre-Conditions: None
  ** Post-Conditions: Player input is obtained.
  *********************************************************************/
	string get_input(int);

  /*********************************************************************
  ** Function: play_game(int, bool)
  ** Description: Starts and plays the game.
  ** Parameters:
  ** s: integer - size of the game grid.
  ** d: boolean - debug mode flag.
  ** Pre-Conditions: None
  ** Post-Conditions: Game is played until completion.
  *********************************************************************/
	void play_game(int, bool);

  /*********************************************************************
  ** Function: populate_event()
  ** Description: Creates events and adds them to the eventArr vector.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Events are created and added to eventArr.
  *********************************************************************/
  void populate_event();

  /*********************************************************************
  ** Function: populate_board()
  ** Description: Places events and the player on the game board.
  ** Parameters: None
  ** Pre-Conditions: Events and eventArr must be populated.
  ** Post-Conditions: Events and player are placed on the game board.
  *********************************************************************/
  void populate_board();

  /*********************************************************************
  ** Function: validPercepts() const
  ** Description: Displays percepts for adjacent rooms.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Percepts for adjacent rooms are printed.
  *********************************************************************/
  void validPercepts() const;

  /*********************************************************************
  ** Function: adjacent(const int, const int) const
  ** Description: Checks if the specified room coordinates are adjacent to the player's current position.
  ** Parameters:
  ** i: integer - x-coordinate of the room.
  ** j: integer - y-coordinate of the room.
  ** Pre-Conditions: None
  ** Post-Conditions: Returns true if the specified room is adjacent to the player's current position, false otherwise.
  *********************************************************************/
  bool adjacent(const int, const int) const;

  /*********************************************************************
  ** Function: move(const string)
  ** Description: Moves the player in a specified direction.
  ** Parameters:
  ** d: string - direction of movement.
  ** Pre-Conditions: None
  ** Post-Conditions: Player is moved accordingly.
  *********************************************************************/
  int move(const string);

  /*********************************************************************
  ** Function: movePlayer(const string)
  ** Description: Moves the player in the specified direction.
  ** Parameters:
  ** d: string - direction of movement.
  ** Pre-Conditions: None
  ** Post-Conditions: Player is moved.
  *********************************************************************/
  void movePlayer(const string);

  /*********************************************************************
  ** Function: handlePool()
  ** Description: Handles effects of pool events.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Effects of pool events are applied.
  *********************************************************************/
  void handlePool();

  /*********************************************************************
  ** Function: valid_wumpus(const string)
  ** Description: Checks if the Wumpus is hit by the player's arrow in the specified direction.
  ** Parameters:
  ** dir: string - direction in which the player fires the arrow.
  ** Pre-Conditions: None
  ** Post-Conditions: Returns true if the Wumpus is hit and killed, false otherwise.
  *********************************************************************/
  bool valid_wumpus(const string);

  /*********************************************************************
  ** Function: kill_wumpus(const int, const int)
  ** Description: Removes the Wumpus from the game board when it is killed by the player's arrow.
  ** Parameters:
  ** wumX: integer - x-coordinate of the Wumpus.
  ** wumY: integer - y-coordinate of the Wumpus.
  ** Pre-Conditions: None
  ** Post-Conditions: The Wumpus is removed from the game board.
  *********************************************************************/
  void kill_wumpus(const int, const int);

  /*********************************************************************
  ** Function: move_wumpus(const int, const int)
  ** Description: Moves the Wumpus to a random adjacent room on the game board when it is not killed by the player's arrow.
  ** Parameters:
  ** wumX: integer - x-coordinate of the Wumpus.
  ** wumY: integer - y-coordinate of the Wumpus.
  ** Pre-Conditions: None
  ** Post-Conditions: The Wumpus is moved to a new random location on the game board.
  *********************************************************************/
  void move_wumpus(const int, const int);

  /*********************************************************************
  ** Function: play_encounters()
  ** Description: Handles encounters with events.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: Encounters with events are processed.
  *********************************************************************/
  int play_encounters();

  /*********************************************************************
  ** Function: valid_end(const int) const
  ** Description: Displays the game result.
  ** Parameters:
  ** message: integer - message indicating specific game result.
  ** Pre-Conditions: None
  ** Post-Conditions: Game result is displayed.
  *********************************************************************/
  void valid_end(const int) const;

};
#endif