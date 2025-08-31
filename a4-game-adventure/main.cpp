/******************************************************
** Program: HUNT THE WUMPUS
** Author: Eric Tran
** Date: 3/17/2024
** Description: Hunt the Wumpus is an adventure game where 
** the player will explore a cave system inhabited by various 
** hazards and creature. The main objective of the game is to 
** locate the gold and escape alive from a dangerous monster 
** lurking within the caves, while avoiding other deadly 
** obstacles.
** Input: length of grid, debug mode, movement key, fire key
** Output: grid, game result, error handling
******************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

int getSideLength() {
    int side_len;
    cout << "Enter side length of the cave (min 4, max 50): ";
    cin >> side_len;
    return side_len;
}

bool getDebugMode() {
    string debug_input;
    cout << "Do you want to run the game in debug mode? (Type true/false): ";
    cin >> debug_input;
    return (debug_input == "true");
}

bool playAgain() {
    string playAgainInput;
    cout << "Do you want to play again? (Type yes/no): ";
    cin >> playAgainInput;
    return (playAgainInput == "yes");
}

int main() {
bool play = true;

    while (play) {
        int side_len = getSideLength();
        if (side_len < 4 || side_len > 50) {
            cout << "Invalid side length. Exiting..." << endl;
            return 1;
        }

        bool debug = getDebugMode();

        Game g;
        g.play_game(side_len, debug);

        play = playAgain();
    }

    return 0;
}
