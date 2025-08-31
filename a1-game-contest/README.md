# A01 — Basketball Shooting Contest (C++)

A two-player NBA-style 3-pt rack simulator. Each player shoots 5 racks; one rack is all money balls. Program validates inputs, simulates makes based on ability, prints rack patterns/scores, and declares the winner.

## TL;DR
- Robust input validation loops (ints, ranges, reprompt on bad input)
- Pseudorandom simulation with seed; simple state machine per rack
- Clean decomposition: `game()`, `play_rack()`, `shoot()`, `calc_winner()`

## Skills Demonstrated
C++ basics • functions & modularity • I/O formatting • defensive programming


## Example Output:
Rack 1: X X O O M | 4 pts  
Rack 2: O O O X X | 3 pts  
...  
Total: 22 pts  
Player 1 is the winner!!  
