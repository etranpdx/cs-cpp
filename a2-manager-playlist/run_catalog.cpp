/******************************************************
** Program: run_catalog.cpp
** Author: Eric Tran
** Date: 2/11/2024
** Description: The Melody Management Corporation (MMC) 
** has recently added a lot of new songs and artists to 
** their catalog. The songs_playlist.txt file contains a 
** list of MMC's songs and their artists. This file will 
** give you the song and artist information that this 
** program will organize and display.
** Input: songs_playlist.txt, userAge
** Output: print to screen or file
******************************************************/
#include "catalog.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string playlistFileName;

    //get user playlist file name
    cout << "Enter the name of the playlist file: ";
    cin >> playlistFileName;

    //file exist validation
    ifstream fin(playlistFileName);

    if (!fin.is_open()) {
        cerr << "Error: Unable to open the playlist file.\n";
        return 1;
    }

    int numPlaylists;
    if (!(fin >> numPlaylists)) {
        cerr << "Error reading the number of playlists.\n";
        return 1;
    }

    cout << "Number of Playlists: " << numPlaylists << endl;
    fin.ignore(); // Consume the newline character

    //age input validation
    int userAge = get_age();

    //create array playlists
    Playlist *playlists = create_playlists(numPlaylists);

    //populate playlists with information from the file
    for (int i = 0; i < numPlaylists; ++i) {
        populate_one_list(playlists, i, fin);
    }

    //close file after reading
    fin.close();

    //runs main menu for user interaction
    runMenuLoop(playlists, numPlaylists, userAge);

    //delete allocated memory
    delete_info(playlists, numPlaylists);

    return 0;
}
