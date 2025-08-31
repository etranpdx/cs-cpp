# A04 — Hunt the Wumpus (C++)

Grid-based cave adventure with hazards and hints. The player explores rooms to find **gold** and return to the **escape rope** while avoiding the **Wumpus** and other hazards. Supports a **debug mode** that reveals event locations; otherwise only percepts (hints) print when adjacent. Fire arrows up to three rooms in a direction to try to slay the Wumpus. 

## TL;DR
- OOP with abstract `Event` and derived `Wumpus`, `Gold`, `Pool`, `Stalactites`; polymorphic `percept()` / `encounter()` / `print_symbol()` 
- Percepts when adjacent: stench (Wumpus), glimmer (Gold), wind (Pool), dripping (Stalactites) 
- Encounters on entry: Wumpus = loss; Stalactites = 50% loss; Pool toggles underwater; Gold can be picked up 
- Arrows: 3-tile range; hit kills Wumpus; miss may move Wumpus (chance) 
- Win: grab gold and return to the start (escape rope) without dying 

## Skills Demonstrated
C++ • inheritance & virtual dispatch • class design (`Room`, `Event`, `Wumpus`, `Gold`, `Pool`, `Stalactites`) • grid traversal • RNG & state updates • input validation (movement bounds, fire constraints)

## Example Output
```text
Enter side length of the cave (min 4, max 50): 5
Do you want to run the game in debug mode? (Type true/false): false

Arrows remaining: 3
Oxygen Level: 10
----- ----- ----- ----- -----
*  ||    ||    ||    ||    ||
   ||    ||    ||    ||    ||
   ||    ||    ||    ||    ||
   ||    ||    ||    ||    ||
   ||    ||    ||    ||    ||
----- ----- ----- ----- -----

You smell a terrible stench.
You hear water dripping.

Player move...
w-up
a-left
s-down
d-right
f-fire an arrow
Enter input: f

Fire an arrow....
w-up
a-left
s-down
d-right
Enter direction: w
You missed! Wumpus has awoken and might've moved.

Player move...
Enter input: s

Arrows remaining: 2
Oxygen Level: 10
----- ----- ----- ----- -----
   ||    ||    ||    ||    ||
*  ||    ||    ||    ||    ||
   ||    ||    ||    ||    ||
   ||    ||    ||    ||    ||
   ||    ||    ||    ||    ||
----- ----- ----- ----- -----

You see a glimmer nearby.

Player move...
Enter input: d
...


