//******************************************************************************
// Author:           Eric Tran
// Assignment:       Assignment 1
// Date:             01/20/24
// Description:      - The purpose of this program is to simulate a basketball 
//                   shooting game. The game will support 2 players, and will 
//                   have each player shoot from 5 fixed positions. Each 4 
//                   racks will compose of 4 normal balls, worth 1 point each 
//                   and 1 money ball, worth 2 points. The 5th rack will be 
//                   composed of only money balls, all worth 2 points each and 
//                   the player will choose which position it is in. Having 
//                   Player 1 shoot from 5 positions first, then Player 2 shoots 
//                   which the player with the highest points at the end is the 
//                   winner. If the players have the same score, then it is a tie.
// Sources:          Assignment 1 specifications
//******************************************************************************

#include <iostream>
#include <cstdlib> 

using namespace std;

char shoot(int shootingAbility) {
    // Function to generates score results
    // param shootingAbility: shooting ability, integer
    // return: score results, char
    int randomNum = rand() % 100 + 1;
    if (randomNum <= shootingAbility) {
        return 'O';  // Made shot
    } else {
        return 'X';  // Missed shot
    }
}


int getNumPlayers() {
  // Gets the numbers of players from user and returns it
  // param: none
  // return: number of players, integer
  int numPlayers;
  do {
      cout << "Enter the number of players: ";
      cin >> numPlayers;
      if (numPlayers < 1 || numPlayers > 100) {
        cout << "That’s not a valid input." << endl;
      }
  } while (numPlayers < 1 || numPlayers > 100);
  return numPlayers;
} 


int getMoneyBallRack() {
    // Gets money ball rack position from user and returns it
    // param: none
    // return: money ball rack position, integer
    int moneyBallRack;
    do {
        cout << "Where do you want to put your money-ball rack? Enter 1-5: ";
        cin >> moneyBallRack;
        if (moneyBallRack < 1 || moneyBallRack > 5) {
          cout << "That’s not a valid input." << endl;
        }
    } while (moneyBallRack < 1 || moneyBallRack > 5);
    return moneyBallRack;
}


int getShootingAbility() {
    // Gets shooting ability from user and returns it
    // param: none
    // return: shooting ability, integer
    int shootingAbility;
    do {
        cout << "Enter your shooting ability, from 1 to 99: ";
        cin >> shootingAbility;
        if (shootingAbility < 1 || shootingAbility > 99) {
          cout << "That’s not a valid input." << endl;
    } 
    } while (shootingAbility < 1 || shootingAbility > 99);
    return shootingAbility;
}


void simulateShooting(char shootingResults[][5], int position, int numBalls, 
int moneyBallRack, int moneyBallPosition, int shootingAbility) {
    // Function to simulate shooting for a rack
    // param shootingResults: 2D array to store shooting results, char
    // param position: position of the rack, integer
    // param numBalls: number of balls in the rack, integer
    // param moneyBallRack: money ball rack position, integer
    // param moneyBallPosition: money ball position, integer
    // param shootingAbility: shooting ability, integer
    // return: none
    for (int ball = 0; ball < numBalls; ++ball) {
        if (position + 1 == moneyBallRack) {
            // The user-specified money ball rack
            shootingResults[position][ball] = shoot(shootingAbility);
            if (shootingResults[position][ball] == 'O') {
                shootingResults[position][ball] = 'M';
            }
        } else {
            // Other racks have 4 regular balls and the last ball can miss
            if (ball == moneyBallPosition - 1) {
                shootingResults[position][ball] = shoot(shootingAbility);
                if (shootingResults[position][ball] == 'O') {
                    shootingResults[position][ball] = 'M';
                }
            } else {
                shootingResults[position][ball] = shoot(shootingAbility);
            }
        }
    }
}


void displayRackResults(char shootingResults[][5], int position, int numBalls, 
int regularBallScore, int moneyBallScore, int &totalScore) {
    // Displays results for the rack
    // param shootingResults: 2D array to store shooting results, char
    // param position: position of the rack, integer
    // param numBalls: number of balls in the rack, integer
    // param regularBallScore: score for regular balls, integer
    // param moneyBallScore: score for money balls, integer
    // param totalScore: total score, integer
    // return: none
    cout << "Rack " << position + 1 << ": ";
    int rackScore = 0;
    for (int ball = 0; ball < numBalls; ++ball) {
        cout << shootingResults[position][ball] << " ";
        if (shootingResults[position][ball] == 'O') {
            rackScore += regularBallScore;  // Regular ball
        } else if (shootingResults[position][ball] == 'M') {
            rackScore += moneyBallScore;  // Money ball
        }
    }
    totalScore += rackScore;
    cout << "| " << rackScore << " pts" << endl;
}


void playRack(char shootingResults[][5], int position, int numBalls, 
int moneyBallRack, int moneyBallPosition, int shootingAbility, 
int regularBallScore, int moneyBallScore, int &totalScore) {
    // Function to play a rack
    // param shootingResults: 2D array to store shooting results, char
    // param position: position of the rack, integer
    // param numBalls: number of balls in the rack, integer
    // param moneyBallRack: money ball rack position, integer
    // param moneyBallPosition: money ball position, integer
    // param shootingAbility: shooting ability, integer
    // param regularBallScore: score for regular balls, integer
    // param moneyBallScore: score for money balls, integer
    // param totalScore: total score, integer
    // return: none
    simulateShooting(shootingResults, position, numBalls, moneyBallRack, 
      moneyBallPosition, shootingAbility);
    displayRackResults(shootingResults, position, numBalls, regularBallScore, 
      moneyBallScore, totalScore);
}


void gameWinner(int playerScores[], int numPlayers) {
    // Declare the winner or tie game
    // param playerScores: array to store player scores, integer
    // param numPlayers: number of players, integer
    // return: none
    int highestScore = 0;
    for (int i = 1; i < numPlayers; ++i) {
        if (playerScores[i] > playerScores[highestScore]) {
          highestScore = i;
        }
    }
    bool tieGame = false;
    for (int i = 0; i < numPlayers; ++i) {
        if (i != highestScore && playerScores[i] == playerScores[highestScore]) {
          tieGame = true;
          break;
        }
    }
    if (!tieGame) {
      cout << "Player " << (highestScore + 1) << " is the winner!!" << endl;
      } else {
          cout << "It's a tie!" << endl;
    }
}


bool askToPlayAgain() {
    // Gets user input if they want to play again
    // param: none
    // return: true if user wants to play again, false otherwise
    int playAgain;
    do {
        cout << "Do you want to play again? (1-yes, 0-no): ";
        cin >> playAgain;

        // Validate play again input
    } while (playAgain != 0 && playAgain != 1);

    return (playAgain == 1);
}


int playGame(int playerNumber, int numPositions, int numBalls, 
int moneyBallPosition, int regularBallScore, int moneyBallScore) {
    // Function to start the game for player
    // param playerNumber: player number, integer
    // param numPositions: number of positions, integer
    // param numBalls: number of balls in each rack, integer
    // param moneyBallPosition: money ball position, integer
    // param regularBallScore: score for regular balls, integer
    // param moneyBallScore: score for money balls, integer
    // return: player score, integer
    char shootingResults[numPositions][5];
    int totalScore = 0;
    cout << "Player " << playerNumber << ":" << endl;

    // Get money-ball rack position from user
    int moneyBallRack = getMoneyBallRack();
    
    // Get shooting ability from user
    int shootingAbility = getShootingAbility();

    for (int position = 0; position < numPositions; ++position) {
        playRack(shootingResults, position, numBalls, moneyBallRack, 
          moneyBallPosition, shootingAbility, regularBallScore, 
          moneyBallScore, totalScore);
    }
    cout << "Total: " << totalScore << " pts" << endl << endl;

    return totalScore;
}


int main() 
{  cout << "Welcome to the basketball shooting contest!" << endl;

    int numPlayers = getNumPlayers();
    
    const int NUM_POSITIONS = 5;
    const int NUM_BALLS = 5;
    const int MONEY_BALL_POSITION = 5;
    const int REGULAR_BALL_SCORE = 1;
    const int MONEY_BALL_SCORE = 2;

    // dynamic array to store player scores
    int* playerScores = new int[numPlayers];

    do {
        for (int player = 1; player <= numPlayers; ++player) {
            playerScores[player - 1] = playGame(player, NUM_POSITIONS, NUM_BALLS, 
              MONEY_BALL_POSITION, REGULAR_BALL_SCORE, MONEY_BALL_SCORE);
        }
        gameWinner(playerScores, numPlayers);
    } while (askToPlayAgain());

    // deallocate dynamic array
    delete[] playerScores;
    cout << "Thank you for playing! Goodbye!" << endl;

    return 0;
}


