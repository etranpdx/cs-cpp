# A02 — Playlist Manager (C++)

A menu-driven CLI that loads a playlist file of song profiles, asks for user age to apply explicit-content filtering, then lets you display songs, search/play a song, search by genre, compute total lengths per playlist, and print results to screen or to a file.

## TL;DR
- Robust input validation (filename exists, positive integer age, valid menu/print choices; reprompt on bad input)
- File I/O + dynamic memory: read song/playlist data into dynamically allocated arrays of `struct`s; optional write-out to a user-named file; proper cleanup
- Clean decomposition: `load_data()`, `display_menu()`, `display_all()`, `search_song()`, `search_by_genre()`, `print_lengths()`, `print_choice()`, `cleanup()`

## Skills Demonstrated
C++ basics • file I/O (`ifstream`/`ofstream`) • dynamic memory (`new`/`delete`) • structs & arrays • input validation • modular design • formatted output

## Example Output:
Enter the playlist info file name: songs_playlist.txt  
Enter your age: -38  
Not valid. Enter a valid age.  
Enter your age: 21  

Which option would you like to choose?  
1. Display all songs  
2. Search for a song to play  
3. Search Songs by Genre  
4. Display length of all playlists  
5. Quit  
Your Choice: 2  

How would you like the information displayed?  
1. Print to screen (Press 1)  
2. Print to file (Press 2)  
Your Choice: 1  
Enter the name of the song: Cruel_Summer  

Here is the info of the song:  
Name: Cruel_Summer  
Artist: Taylor_Swift  
Year Released: 2019  
Length: 4.12 minutes  
Genre: Pop  
Restriction: None  
