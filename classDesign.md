# Class design

## Overall game design ideas

- The game is split up into different classes that comprise all the objects and functionality of the game
- The levels (created from the Level class) consist of a map (created from the Map class) that includes an array of 
  characters that visually represents the dungeon and all the objects in it
- The Player class controls player actions and the player can move through the dungeon with keyboard commands, gain
  points by collecting gems or fighting monsters, lose energy by moving or fighting monsters, and gain energy by
  collecting magic apples
- The GameManager and LevelManager manage the running of the game by creating and loading levels, and running the game
  loop
- Each object that is not part of the map is inherited from the GameObject class and contains extra functionality unique
  to the object

## Classes used in the game

Below is a list of classes used in the game. Each heading is the name of a class.

******** gameObjects ********

### GameObject

- Member variables: char symbol, Position position
- Member functions:
    - Constructors for instantiating game objects with different variables
    - Getters and setters for symbol and position variables
- Description: The GameObject class is the base class for the objects in the game, excluding walls, floors and entrances
  that make up the map. The Player, Gem, MagicApple and Monster classes inherit from the GameObject class.

### Gem

- Member variables: int value
- Member functions:
    - Constructors for instantiating gems with different variables
    - Getter and setter for the value variable
- Description: The Gem class contains the symbol and value of gems. The player can pick up gems in the map and gains
  points equal to the value of the gem.

### MagicApple

- Member variables: int energyRestored
- Member functions:
    - Constructors for instantiating magic apples with different variables
    - Getter and setter for the energyRestored variable
- Description: The MagicApple class contains the symbol and value for how much energy magic apples restore. The player
  can pick up magic apples in the map and gains energy equal to the value energy restored by the magic apple.

### Monster

- Member variables: int strength
- Member functions:
    - Constructors for instantiating monsters with different variables
    - Getter and setter for the strength variable
- Description: The Monster class contains the symbol and value for how much energy magic apples restore. The player can
  move onto a monster's tile and the fight the monster. The player will lose energy equal to the monster's strength, but
  if the player still has energy left after the fight they will also gain points.

### Player

- Member variables:
    - int energy;
    - int points;
    - std::string name;
    - bool isAtEntrance = false;
    - bool foundEntrance = false;
    - char symbolInteractingWith;
- Member functions:
    - Player()
    - Getters and setters for the member variables
    - `void move(std::string action, Map &map)` moves the player by moving the player's symbol to a new position based
      on user input
- Description: The Player class represents the playable character and is in charge of player actions, such as moving and
  interacting with other objects on the map.

******** helperClasses ********

### EventLogger

- Member variables: std::vector<std::string> events;
- Member functions:
    - EventLogger()
    - void addEvent(std::string event)
    - void printEvents()
    - std::string getTime();
- Description: The EventLogger class is responsible for storing for descriptions of events that happen during the game,
  e.g. if the player wins a monster fight or finds a new level. The EventLogger object will print out all the event
  descriptions at the end of the game.

### Position

- Member variables: int xCoordinate, int yCoordinate
- Member functions:
    - Constructors for instantiating position objects with different variables
    - Getters and setters for the member variables
- Description: the Position class is responsible for creating position objects that represent a two-dimensional
  coordinate on the game map. Game objects have positions, so the Position class is used by GameObjects to determine
  their position and by the Map class to place objects at certain locations on the map.

******** levels ********

### Level

- Member variables:
    - int mapWidth = 11, mapHeight = 7;
    - int movementCost;
    - int levelNumber, levelMaxNumber;
    - std::vector<GameObject> gems;
    - std::vector<GameObject> monsters;
    - std::vector<GameObject> magicApples;
    - Monster monster;
    - Gem gem;
    - MagicApple magicApple;
- Member functions
    - Level()
    - Getters and setters for member variables
    - `void setMovementCost()` does not have any parameters because it sets the movement cost to equal the number of the
      current level
    - void addMonstersToVector(int numToAdd)
    - void addGemsToVector(int numToAdd);
    - void addMagicApplesToVector(int numToAdd);
- Description: The Level class represents a single level in the game. This class is responsible for setting movement
  costs, the level's map size and controls the gems, monsters and magic apples for the current level. The Level class is
  mainly used by the LevelManager to create new levels. It also uses the GameObject child classes.

### Map

- Member variables:
    - char symbolWall = SYMBOL_WALL;
    - char symbolFloor = SYMBOL_FLOOR;
    - char symbolEntrance = SYMBOL_ENTRANCE;
    - int width, height;
    - char *charMap;
- Member functions:
    - Constructors and destructor for Map objects
    - Getters and setters for member variables
    - `char* makeCharMap()` creates the map by creating a dynamically allocated array that is filled with characters
      representing wall and floor tiles
    - char getCharAtPosition(Position position) const
    - int getIndexAtPosition(int x, int y) const
    - void addEntrance();
    - Map& operator= (const Map &map);
    - char getCharAtPosition(int x, int y) const;
    - Position getRandomPosition();
    - void printMap()
- Description: the Map class is responsible for creating Map objects that create and print the visible map for each
  level. The Map class is used mainly by the LevelManager to create new maps for new levels or print current levels. The
  Player class also uses the map to move the Player symbol according to user input.

******** managers ********

### GameManager

- Member variables:
    - int levelCurrent;
    - LevelManager levelManager;
    - EventLogger eventLogger;
    - Player player;
- Member functions:
    - GameManager();
    - void checkShouldQuitGame(string playerAction);
    - [[noreturn]] void gameLoop();
    - string getUserInput(string message) const;
    - void handleInteractionWithEntrance();
    - void handleInteractionWithGem();
    - void handleInteractionWithMagicApple();
    - void handleInteractionWithMonster();
    - void handlePlayerInteraction();
    - void printPlayerStats() const;
    - [[noreturn]] void startGame();
    - void quitGame() const;
- Description: The GameManager manages the game by instantiating other objects and calling necessary functions to make
  the game run. The GameManager starts and quits the game. The GameManager works mainly with the LevelManager,
  EventLogger and Player classes, which it has as member variables.
  
### LevelManager

- Member variables:
    - Level level;
    - bool entranceIsAdded = false;
    - Map map;
- Member functions:
    - void addGameObjectsToMap(std::vector<GameObject> objects, Map &map);
    - int getGameObjectValue(int extraValue) const;
    - int getLevelNumber() const;
    - Gem getGem();
    - MagicApple getMagicApple();
    - Monster getMonster();
    - int getMovementCost() const;
    - int getNumberOfObjectsToAdd(Map &map);
    - void makeNewMap(Player &player);
    - void selectAndPrintLevel(Player &player, int levelCurrent);
    - void setLevel(int levelNumber);
- Description: The LevelManager manages the loading and displaying of different levels. It also manages the game 
  objects for each level. The LevelManager works with the GameManager and the GameObject child classes to create levels.