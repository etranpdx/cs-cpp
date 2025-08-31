#include "catalog.h"
#include <fstream>

using namespace std;

//function definitions go here
void displayAllSongs(Playlist* playlists, int numPlaylists, int userAge, 
int outputChoice);


int get_age() {
    int userAge;
    while (true) {
        cout << "Enter your age (must be a positive integer): ";
        cin >> userAge;
        //checks input failure or non-integer input
        if (cin.fail() || userAge <= 0) {
            cin.clear();  // Clear the error flag
            cin.ignore();  // Discard invalid input
            cout << "Invalid input. Please enter a positive integer for your age.\n";
        } else {
            break;  //exit loop if valid age is entered
        }
    }
    return userAge; //return user's age
}


void runMenuLoop(Playlist* playlists, int numPlaylists, int userAge) {
    int choice;

    do {
        displayMenu();            //display options menu
        cout << "Your Choice: ";  //get user choice
        cin >> choice;
        cout << endl;

        //input validation for choice
        while (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();  //clear error flag
            cin.ignore();  //discard invalid input
  cout << "Invalid choice. Please enter a number between 1 and 5.\n" << "Your Choice: ";
  cin >> choice;
  cout << endl;
        }
        if (choice != 5) {
            displayOutputMenu();  //display output menu
            cout << "Your Choice: ";
            int outputChoice;

            //input validation for outputChoice
            cin >> outputChoice;
            while (cin.fail() || outputChoice < 1 || outputChoice > 2) {
                cin.clear();  //clear error flag
                cin.ignore();  //discard invalid input
  cout << "Invalid choice. Please enter 1 or 2.\n" << "Your Choice: ";
                cin >> outputChoice;
            }
  cout << endl;
            //choice is determined to call a specific function
            processChoice(choice, playlists, numPlaylists, userAge, outputChoice);
        }
    } while (choice != 5);
}


//allocates memory for array of playlists
Playlist* create_playlists(int numPlaylists) {
  return new Playlist[numPlaylists];
}


//populates info for one playlist at a time from input file
void populate_one_list(Playlist* playlists, int index, ifstream& inputFile) {
    //reads each attribute directly from file
    inputFile >> playlists[index].name >> playlists[index].num_song;
    //dynamically allocates memory for songs in playlist
    playlists[index].s = create_songs(playlists[index].num_song);
    //populates songs in playlist using loop
    for (int i = 0; i < playlists[index].num_song; ++i) {
        populate_one_song(playlists[index].s, i, inputFile);
    }
    //adds total length of songs in playlist
    playlists[index].total_len = 0.0; 
    for (int i = 0; i < playlists[index].num_song; ++i) {
        playlists[index].total_len += playlists[index].s[i].length;
  }
}


//creates array of songs
Song* create_songs(int size) {
        return new Song[size];
}


//populates one song at a time from input file
void populate_one_song(Song* songs, int index, ifstream& fin) {
    fin >> songs[index].name >> songs[index].artist >> songs[index].year_release 
      >> songs[index].length >> songs[index].genre >> songs[index].res;
}


//deallocate memory for arrays songs and playlists
void delete_info(Playlist* playlists, int size) {
      for (int i = 0; i < size; ++i) {
          delete[] playlists[i].s;    //free memory for songs array in each playlist
          playlists[i].s = nullptr;    
      }
      delete[] playlists; //free memory for the playlists array
}


void displayMenu() {
    cout << "\nWhich option would you like to choose?\n";
    cout << "1. Display all songs\n";
    cout << "2. Search for a song to play\n";
    cout << "3. Search Songs by Genre\n";
    cout << "4. Display length of all playlists\n";
    cout << "5. Quit\n";
}


void displayOutputMenu() {
    cout << "How would you like the information displayed?\n";
    cout << "1. Print to screen (Press 1)\n";
    cout << "2. Print to file (Press 2)\n";
}


//processes user choice
void processChoice(int choice, Playlist* playlists, int numPlaylists, int userAge, 
int outputChoice) {
    if (choice == 1) {
        displayAllSongs(playlists, numPlaylists, userAge, outputChoice);
    } else if (choice == 2) {
        playSearchSong(playlists, numPlaylists, outputChoice);
    } else if (choice == 3) {
        searchSongsByGenre(playlists, numPlaylists, outputChoice);
    } else if (choice == 4) {
        lengthOfAllPlaylists(playlists, numPlaylists, outputChoice);
    } else if (choice != 5) {
        cout << "Invalid choice. Please try again.\n";
    }
}


//displays all songs and playlist from file
void displayAllSongs(Playlist* playlists, int numPlaylists, int userAge, 
int outputChoice) {
    if (outputChoice == 1) {
        for (int i = 0; i < numPlaylists; ++i) {
            cout << "Playlist: " << playlists[i].name << "\n";
            for (int j = 0; j < playlists[i].num_song; ++j) {
                Song currentSong = playlists[i].s[j];
                if (userAge <= 19 && currentSong.res == "E") {   //skip explicit songs for users aged below 20
                    continue;
                }
                printSongInfo(currentSong);
            }
        }
    } else if (outputChoice == 2) {     //prints to file
        for (int i = 0; i < numPlaylists; ++i) {
            toFileDisplayAll(playlists[i], userAge);
        }
    } else {
        cout << "Invalid output choice.\n";
    }
}


void playSearchSong(Playlist* playlists, int numPlaylists, int outputChoice) {
    cin.ignore();  // Clear the newline character from the buffer
    string songName;
    cout << "Enter the name of the song: ";
    getline(cin, songName);
    bool songFound = false;
    for (int i = 0; i < numPlaylists; ++i) {
        for (int j = 0; j < playlists[i].num_song; ++j) {
            Song currentSong = playlists[i].s[j];
            if (currentSong.name == songName) {
                songFound = true;
                if (outputChoice == 1) {
                    printSongInfo(currentSong);
                } else if (outputChoice == 2) {
                    toFileSearch(currentSong);
                } else {
                    cout << "Invalid output choice.\n";
                    return;
                }
                return;
            }
        }
    }
    if (!songFound) {
        cout << "Song not found.\n";
    }
}


void searchSongsByGenre(const Playlist* playlists, int numPlaylists, int outputChoice) {
    string genre;
    cout << "Enter the genre: ";
    cin >> genre;
    if (outputChoice == 1) {
        for (int i = 0; i < numPlaylists; ++i) {
            for (int j = 0; j < playlists[i].num_song; ++j) {
                Song currentSong = playlists[i].s[j];
                if (currentSong.genre == genre) {
                    printSongInfo(currentSong);
                }
            }
        }
    } else if (outputChoice == 2) {
        for (int i = 0; i < numPlaylists; ++i) {
            toFileSearchSongsByGenre(playlists[i], genre);
        }
    } else {
        cout << "Invalid output choice.\n";
    }
}


void lengthOfAllPlaylists(Playlist* playlists, int numPlaylists, 
int outputChoice) {
    //loops through total length of each playlist and totals it
    for (int i = 0; i < numPlaylists; ++i) {
        float totalLength = 0.0;
        for (int j = 0; j < playlists[i].num_song; ++j) {
            totalLength += playlists[i].s[j].length;
        }
        if (outputChoice == 1) {
            cout << playlists[i].name << ": " << totalLength << " minutes\n";
        } else if (outputChoice == 2) {
            ofstream outFile("output.txt", ios::app); //append to output file

            if (!outFile.is_open()) {
                cerr << "Error: Unable to open the output file.\n";
                return;
            }
            outFile << playlists[i].name << ": " << totalLength << " minutes\n";
        } else {
            cout << "Invalid output choice.\n";
            return;
        }
    }
}


//print to file searched song
void toFileSearch(const Song& searchedSong) {
    ofstream outFile("output.txt", ios::app); //append to output file
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the output file.\n";
        return;
    }
    outFile << "Here is the info of the song:\n" << "-------------------------------\n" 
    << "Name: " << searchedSong.name << "\n" << "Artist: " << searchedSong.artist << "\n"
    << "Year Released: " << searchedSong.year_release << "\n" << "Length: " << searchedSong.length 
    << " minutes\n" << "Genre: " << searchedSong.genre << "\n" << "Restriction: " 
    << searchedSong.res << "\n" << "-------------------------------\n";
    outFile.close();    // close the file
}


//print to file display all 
void toFileDisplayAll(const Playlist& playlist, int userAge) {
    ofstream outFile("output.txt", ios::app); //append to output file
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the output file.\n";
        return;
    }
    outFile << "Playlist: " << playlist.name << "\n";
    for (int j = 0; j < playlist.num_song; ++j) {
        Song currentSong = playlist.s[j];
    outFile << "-------------------------------\n" << "Name: " << currentSong.name << "\n" 
    << "Artist: " << currentSong.artist << "\n" << "Year Released: " 
    << currentSong.year_release << "\n" << "Length: " << currentSong.length << " minutes\n"
    << "Genre: " << currentSong.genre << "\n" 
    << "Restriction: " << currentSong.res << "\n" << "-------------------------------\n";
    }
    //close file
    outFile.close();
}


void toFileSearchSongsByGenre(const Playlist& playlist, const string& genre) {
    ofstream outFile("output.txt", ios::app); //appends to output file

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the output file.\n";
        return;
    }
    for (int j = 0; j < playlist.num_song; ++j) {
        Song currentSong = playlist.s[j];
        if (currentSong.genre == genre) {
    outFile << "-------------------------------\n" << "Name: " << currentSong.name << "\n" 
    << "Artist: " << currentSong.artist << "\n" << "Year Released: " 
    << currentSong.year_release << "\n" << "Length: " << currentSong.length << " minutes\n" 
    << "Genre: " << currentSong.genre << "\n" << "Restriction: " 
    << currentSong.res << "\n" << "-------------------------------\n";
        }
    }
    //close file
    outFile.close();
}


//printing format
void printSongInfo(const Song& song) {
    cout << "-------------------------------\n";
    cout << "Name: " << song.name << "\n";
    cout << "Artist: " << song.artist << "\n";
    cout << "Year Released: " << song.year_release << "\n";
    cout << "Length: " << song.length << " minutes\n";
    cout << "Genre: " << song.genre << "\n";
    cout << "Restriction: " << song.res << "\n";
    cout << "-------------------------------\n";
}


  