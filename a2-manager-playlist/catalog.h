#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;
struct Song;

//a struct to hold info of a Playlist
struct Playlist {
	string name;        //name of the playlist, one word
	int num_song;       //number of songs in the playlist
	struct Song *s;     //an array that holds all songs in the playlist
	float total_len;    //total length of the playlist
};

//a struct to hold info of a Song
struct Song {
	string name;		//name of the song, one word
	string artist;		//name of the artist, one word
	int year_release;	//the year of release
	float length;		//length of the song
	string genre;		//genre of the song, one word
	string res;			//"E" or "none" for restriction level
};


/**************************************************
 * Name: create_playlists()
 * Description: This function will dynamically allocate
				an array of playlists (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Playlist array of requested size is created and return
 ***********************************************/
Playlist* create_playlists(int);


/**************************************************
 * Name: populate_one_list()
 * Description: This function will fill a single playlist struct 
				with information that is read in from the file
 * Parameters:  Playlist* - pointer to the Playlist array
				int - index of the Playlist in the array to be filled 
				ifstream& - input file to get the Playlist information
 * Pre-conditions: Playlist array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Playlist at provided index is populated
 ***********************************************/
void populate_one_list(Playlist*, int, ifstream &); 


/**************************************************
 * Name: create_songs()
 * Description: This function will dynamically allocate
				an array of songs (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Song array of requested size is created and return
 ***********************************************/
Song* create_songs(int);


/**************************************************
 * Name: populate_one_song()
 * Description: This function will fill a single song struct 
				with information that is read in from the file
 * Parameters:  Song* - pointer to the Song array
				int - index of the Song in the array to be filled 
				ifstream& - input file to get the Song information
 * Pre-conditions: Song array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Song at provided index is populated
 ***********************************************/
void populate_one_song(Song*, int, ifstream &); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Playlist* - the Playlist array
 * Pre-conditions: the provided Playlist array hasn't been freed yet
 * Post-conditions: the Playlist array, with all Songs inside, is freed
 ***********************************************/
void delete_info(Playlist*, int);


/**************************************************
 * Name: get_age
 * Description: Obtains the user's age from input
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: returns user's age
 ***********************************************/
int get_age();

/**************************************************
 * Name: runMenuLoop
 * Description: Runs main menu for user interaction
 * Parameters: Playlist* - array of playlists, int - number of playlists, int - user's age
 * Pre-conditions: playlist array initialized, user's age valid
 * Post-conditions: exits loop when user quits
 ***********************************************/
void runMenuLoop(Playlist* playlists, int numPlaylists, int userAge);


/**************************************************
 * Name: displayMenu
 * Description: Displays the main menu options.
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ***********************************************/
void displayMenu();


/**************************************************
 * Name: displayOutputMenu
 * Description: Displays options for output preferences.
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ***********************************************/
void displayOutputMenu();


/**************************************************
 * Name: processChoice
 * Description: Processes user's menu choice
 * Parameters: int - user's choice, Playlist* - array of playlists, int - number of playlists, int - user's age, int - output choice
 * Pre-conditions: playlist array  initialized, user's age valid, output choice valid
 * Post-conditions: executes choice
 ***********************************************/
void processChoice(int, Playlist*, int, int, int);


/**************************************************
 * Name: displayAllSongs
 * Description: Displays information about all songs in the playlists
 * Parameters: Playlist* - array of playlists, int - number of playlists, int - user's age, int - output choice
 * Pre-conditions: playlist array initialized, user's age valid, output choice valid
 * Post-conditions: displays song information
 ***********************************************/
void displayAllSongs(Playlist*, int, int, int);


/**************************************************
 * Name: playSearchSong
 * Description: Searches for and displays or saves a specific song
 * Parameters: Playlist* - array of playlists, int - number of playlists, int - output choice
 * Pre-conditions: playlist array initialized, user's age is valid, output choice valid
 * Post-conditions: displays or saves information of specific song
 ***********************************************/
void playSearchSong(Playlist*, int, int);


/**************************************************
 * Name: searchSongsByGenre
 * Description: Searches for and displays songs of a specific genre
 * Parameters: const Playlist* - array of playlists, int - number of playlists, const string& - genre
 * Pre-conditions: playlist array initialized, user's age valid, genre input valid
 * Post-conditions: displays information about songs of a specific genre
 ***********************************************/
void searchSongsByGenre(const Playlist*, int, int);


/**************************************************
 * Name: lengthOfAllPlaylists
 * Description: Displays or saves the total length of all playlists
 * Parameters: Playlist* - array of playlists, int - number of playlists, int - output choice
 * Pre-conditions: playlist array initialized, user's age valid, output choice valid
 * Post-conditions: displays or saves total length of all playlists
 ***********************************************/
void lengthOfAllPlaylists(Playlist*, int, int);


/**************************************************
 * Name: toFileSearch
 * Description: Saves information about a specific song to a file
 * Parameters: const Song& - reference to the song
 * Pre-conditions: song struct initialized, user's age valid
 * Post-conditions: saves information of specific song to file
 ***********************************************/
void toFileSearch(const Song& song);


/**************************************************
 * Name: toFileDisplayAll
 * Description: Saves information about all songs in a playlist to a file
 * Parameters: const Playlist& - reference to the playlist, int - user's age.
 * Pre-conditions: playlist struct initialized, user's age valid.
 * Post-conditions: saves information about all songs in a playlist to a file based on user input
 ***********************************************/
void toFileDisplayAll(const Playlist& playlist, int userAge);


/**************************************************
 * Name: toFileSearchSongsByGenre
 * Description: Saves information about songs of a specific genre to a file
 * Parameters: const Playlist& - reference to the playlist, int - user's age, const string& - genre
 * Pre-conditions: playlist struct initialized, user's age valid, genre input valid
 * Post-conditions: saves information of songs of specific genre to output file
 ***********************************************/
void toFileSearchSongsByGenre(const Playlist&, const string&);


/**************************************************
 * Name: printSongInfo()
 * Description: Prints the song information
 * Parameters: the Song struct.
 * Pre-conditions: song struct  initialized
 * Post-conditions: the song information is printed
 ***********************************************/
void printSongInfo(const Song& song);



#endif