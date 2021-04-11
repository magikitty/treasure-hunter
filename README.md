# Treasure Hunter

Treasure Hunter is a CLI-based game where the player tries to survive in a dungeon while collecting as many gems as 
possible.

## Overview

- 15 levels
- Each new level:
    - Is larger than the previous
    - Contains stronger monsters  
    - Possibly contains more monsters
- Moving to an exit tile (E) exits the level into a new level
- Walking: moving to a new floor (.) tile consumes energy
- Walls: moving to wall (#) tiles is not possible
- Fighting: moving to a monster tile (M) consumes energy
- Gaining energy: moving to a magic apple tile (A) consumes energy
- Dying: losing all energy leads to death
- Gaining points: moving to a gem tile (G) consumes energy
- Portal out: Pressing "p" ends the game