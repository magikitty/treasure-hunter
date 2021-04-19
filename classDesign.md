# Class design

## Overall game design ideas

-

## Classes used in the game

Below is a list of classes used in the game. Each heading is the name of a class.

******** gameObjects ********

### GameObject

- Member variables: char symbol, Position position
- Member functions:
    - Constructors for instantiating game objects with different variables
    - Getters and setters for symbol and position variables
- Description: The GameObject class is the base class for the objects in the game, excluding walls, floors and 
  entrances that make up the map. The Player, Gem, MagicApple and Monster classes inherit from the GameObject class.

### Gem

- Member variables: int value
- Member functions:
    - Constructors for instantiating gems with different variables
    - Getter and setter for the value variable
- Description: The Gem class contains the symbol and value of gems. The player can pick up gems in the map and gains 
  points equal to the value of the gem.
  
## MagicApple

- Member variables: int energyRestored
- Member functions:
    - Constructors for instantiating magic apples with different variables
    - Getter and setter for the energyRestored variable
- Description: The MagicApple class contains the symbol and value for how much energy magic apples restore. The player 
  can pick up magic apples in the map and gains energy equal to the value energy restored by the magic apple.
  
## Monster

- Member variables: int strength
- Member functions:
    - Constructors for instantiating monsters with different variables
    - Getter and setter for the strength variable
- Description: The Monster class contains the symbol and value for how much energy magic apples restore. The player
  can move onto a monster's tile and the fight the monster. The player will lose energy equal to the monster's 
  strength, but if the player still has energy left after the fight they will also gain points.
  
## Player
- Member variables:
  - int energy;
  - int points;
  - std::string name;
  - bool isAtEntrance = false;
  - bool foundEntrance = false;
- Member functions:
    - `Player()` is default constructor for instantiating a Player object; it sets the player's initial points, energy,
    name and position
    - Getters and setters for the member variables
    - `void move(std::string action, Map &map)` moves the player by moving the player's symbol to a new position based 
    on user input
    - `void selectInteraction(char symbol)` selects an interaction if the player walks onto a tile containing a 
      symbol other than a floor symbol. For example, walking onto an entrance symbol will move the player to a new 
      level and walking onto a magic apple symbol will restore the player's energy.
- Description: The Player class represents the playable character and is in charge of player actions, such as moving 
  and interacting with other objects on the map.

******** helperClasses ********

### EventLogger

- Member variables: std::vector<std::string> events;
- Member functions:
  - `EventLogger()` constructor
  - `void addEvent(std::string event)` adds a given string to the events vector
  - `void printEvents()` prints out each string stored in the events vector
- Description: The EventLogger class is responsible for storing for descriptions of events that happen during the 
  game, e.g. if the player wins a monster fight or finds a new level. The EventLogger object will print out all the 
  event descriptions at the end of the game.
  
## Position

- Member variables: int xCoordinate, int yCoordinate
- Member functions:
  - Constructors for instantiating position objects with different variables
  - Getters and setters for the member variables
- Description: the Position class is responsible for creating position objects that represent a two-dimensional 
  coordinate on the game map. Game objects have positions, so the Position class is used by GameObjects to determine 
  their position and by the Map class to place objects at certain locations on the map.