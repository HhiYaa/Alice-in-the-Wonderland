# Alice-in-the-Wonderland
Text-based Game using C++ Programming Language 
Design Document for "Alice in Wonderland" Text-Based Game

Concept and Overview

"Alice in Wonderland" is a text-based adventure game inspired by Lewis Carroll's classic novel. The game allows players to immerse themselves in a whimsical world, interact with various characters, and navigate through different locations while solving puzzles and facing challenges. The primary goal of the game is to guide Alice through Wonderland, helping her overcome obstacles and ultimately find her way home.

Game Design Elements
 Storyline
The game follows Alice's adventures in Wonderland, encountering iconic characters like the White Rabbit, the Cheshire Cat, the Mad Hatter, and the Queen of Hearts. Players make decisions that influence the storyline and Alice's interactions with other characters, leading to different outcomes and endings.

Gameplay
-	The player starts at the Rabbit Hole and moves through different locations by issuing text commands.
-	Exploration: Players navigate through different locations in Wonderland, discovering new areas, and interacting with objects and characters.
-	Commands include moving in directions (north, south, east, west), interacting with characters, taking items, using items, and checking inventory.
-	Character Interaction: Players interact with various characters, which can affect the storyline based on their choices.
-	Points are awarded for various actions such as discovering new locations, solving puzzles, and interacting with characters.
-	The game has a mix of friendly and hostile characters, requiring the player to choose between fighting or fleeing in certain encounters.
-	Combat: Players engage in turn-based combat with enemies.
-	Certain items activate enemies or unlock new interactions in specific locations.

Goals
Primary Goal: Guide Alice through Wonderland and help her find her way to the Queens Castle.
Secondary Goals: 
-	Engage in mini games, such as playing chess with the Queen.
-	Collect valuable items and use them appropriately to advance in the game.
-	Interact with characters to gain points and uncover hidden aspects of the story.
-	Fighting off all the enemy characters along the game. 

Design Elements
Locations
-	Rabbit Hole: Starting point with basic items like Food, Flashlight, and Rock.
-	Hallway of Doors: Contains items like Sword, DrinkMePotion, and Cake.
-	Enchanted Garden: Magical garden with items like Tea and Dormouse.
-	Mad Hatter's Tea Party: Contains items like Mushroom, Gold Jewelry, Cheshire Cat's Smile, and Golden Key.
-	Queen's Rose Garden: Includes items like Dormouse and ChessGame.
-	Queen's Castle: Final location, only accessible after playing chess with the Queen.
-	Courtroom: A potential location based on certain interactions.
Items
-	Food, Flashlight, Rock: Basic items found at the Rabbit Hole.
-	Sword: Used to fight enemies.
-	DrinkMePotion, Cake: Alters player's size.
-	Tea: A consumable item.
-	Mushroom, Gold Jewelry, Cheshire Cat's Smile, Golden Key: Found at the Mad Hatter's Tea Party with unique uses.
-	Dormouse, ChessGame: Found at Queen's Rose Garden, used in specific interactions.
-	Crown: Found at Queen's Castle.
Characters
-	White Rabbit: Guides the player initially.
-	Mad Hatter: Provides riddles and interactions.
-	Queen of Hearts: Challenges the player to a chess game.
-	Cheshire Cat: Provides hints and points.
-	Hostile Characters: Various enemies that can be fought or fled from.
Commands
-	Movement: go north, go south, go east, go west
-	Interaction: interact [character]
-	Item Management: take [item], use [item], eat [item]
-	Inventory Check: inventory
-	Game Information: look
-	Exit: quit
Game Plan
1.	Initial Setup
-	The game initializes with the player at the Rabbit Hole.
-	Items and characters are loaded into their respective locations from text files.
-	The game guide is displayed to the player.

2.	Main Loop
-	The game runs in a loop, waiting for player commands.
-	Based on the command, the game processes movement, interaction, item management, or game information requests.
-	Points are awarded for various achievements and actions.

3.	Ending Conditions
-	The game ends when the player successfully reaches the Queen's Castle and wins or chooses to quit.
-	The final score is displayed upon ending the game.


Classes and Text Files
Classes

1. `Action`
Handles actions that can be performed in the game, such as moving, interacting with objects, or using items.

Attributes: 
  - `name`: The name of the action.
  - `actionFunc`: The function that executes the action.
  - `description`: Description of the action.
Methods:
  - `Action()`: Constructor to initialize an action.
  - `perform()`: Executes the action.
  - `getName()`: Returns the name of the action.
  - `getDescription()`: Returns the description of the action.

2. `Character`
Represents characters in the game, including Alice, enemies, and friendly characters.

Attributes:
  - `name`: The name of the character.
  - `description`: Description of the character.
  - `friendly`: Boolean indicating if the character is friendly.
  - `health`: Health points of the character.
  - `attackPower`: Attack power of the character.
Methods:
  - `Character()`: Constructor to initialize a character.
  - `getName()`: Returns the name of the character.
  - `getDescription()`: Returns the description of the character.
  - `isFriendly()`: Returns if the character is friendly.
  - `isEnemy()`: Returns if the character is an enemy.
  - `getHealth()`: Returns the health of the character.
  - `getAttackPower()`: Returns the attack power of the character.
  - `reduceHealth()`: Reduces the health of the character.
  - `attack()`: Attacks another character.
  - `interact()`: Interacts with the character.

3. `Control`
Manages game flow and processes user commands.
Attributes:
  - `locations`: Map of location names to `Location` objects.
  - `currentLocation`: Pointer to the current location.
  - `inventory`: Pointer to the player's inventory.
  - `characters`: Vector of characters.
  - `visitedLocations`: Set of visited locations.
  - `itemDesc`: Map of item names to descriptions.
  - `player`: Pointer to the player character.
  - `points`: Points in the game.
  - `health`: Health of the player.
Methods:
  - `Control()`: Constructor to initialize the control system.
  - `run()`: Runs the game.
  - `addPoints()`: Adds points to the player's score.
  - `initializeGame()`: Initializes the game.
  - `displayGameGuide()`: Displays the game guide.
  - `processCommand()`: Processes a user command.
  - `fightCharacter()`: Handles fighting a character.
  - `fleeFromCharacter()`: Handles fleeing from a character.
  - `ExitLists()`: Exits lists.
  - `useItem()`: Uses an item.
  - `playChessWithQueen()`: Plays chess with the Queen.
  - `handleEnemyInteraction()`: Handles enemy interaction.
  - `interactCharacter()`: Interacts with a character.
  - `handleItemPickup()`: Handles item pickup.
  - `take()`: Takes an item.
  - `interactInCourtroom()`: Interacts in the courtroom.
  - `interactWithQueen()`: Interacts with the Queen.
  - `trim()`: Trims whitespace from a string.
  - `toLower()`: Converts a string to lowercase.
  - `getNextLocation()`: Gets the next location.

4. `Inventory`
Manages the player's inventory.
Attributes:
  - `items`: Vector of items in the inventory.
Methods:
  - `addItem()`: Adds an item to the inventory.
  - `listItems()`: Lists all items in the inventory.
  - `removeItem()`: Removes an item from the inventory.
  - `hasItem()`: Checks if the inventory has an item by name.

5. `Item`
Represents items in the game.
Attributes:
  - `name`: The name of the item.
  - `description`: Description of the item.
  - `points`: Points associated with the item.
Methods:
  - `Item()`: Constructor to initialize an item.
  - `getName()`: Returns the name of the item.
  - `getDescription()`: Returns the description of the item.
  - `getPoints()`: Returns the points of the item.
  -`addPoints()`: Adds points to the player's score.

Text Files
Locations.txt: Contains descriptions and details of all locations in the game.
Characters.txt: Contains details about all characters, including names, descriptions, and attributes.
Items.txt: Contains details about all items, including names, descriptions, and points.
Actions.txt: Provides a actions for the player on how to play the game.

 Class Descriptions
1.	Control
Manages the overall game flow.
Processes player commands.
Handles interactions with characters and items.
Tracks points and player progress.
Methods include run, addPoints, initializeGame, processCommand, playChessWithQueen, and handleEnemyInteraction.
2.	Location
Represents different places in the game.
Stores items and characters in the location.
Manages exits to other locations.
Methods include addItem, removeItem, addCharacter, removeCharacter, setExit, getExit, describe, hasItem, hasCharacter, hasEnemies, loadCharactersFromFile, and loadItemsFromFile.
3.	Item
Represents objects that the player can interact with or collect.
Stores item names and descriptions.
Methods include getName and getDescription.
4.	Character
Represents both friendly and hostile characters in the game.
Stores character names and descriptions.
Handles interaction logic.
Methods include getName, getDescription, and interact.
5.	Inventory
Manages the player's collected items.
Allows adding, removing, and listing items.
Methods include addItem, removeItem, hasItem, getItem, and listItems.
 Text Files Used
1.	characters.txt
-	Stores information about characters in the game.
-	Each line represents a character with a name and description.
-	Format: CharacterName, CharacterDescription

2.	items.txt
-	Stores information about items in the game.
-	Each line represents an item with a name and description.
-	Format: ItemName, ItemDescription\

3.	Action.txt
-	Stores information about Actions in the game.
-	Each line represents an Actions with a name and description.
-	Format: ActionName, ActionDescription

4.	Location,txt
-	Stores information about Locations in the game.
-	Each line represents an Locations with a name and description.
-	Format: LocationName, LocDesc
-	It also describes the characters and items thare associate to each specific locations. 

Research and Development

Research
Source Material: The primary source of inspiration was Lewis Carroll's "Alice's Adventures in Wonderland" and "Through the Looking-Glass." The whimsical and surreal nature of the story provided a rich backdrop for a text-based adventure game.
Game Design: Research into classic text-based adventure games, such as Zork and The Hitchhiker's Guide to the Galaxy, provided insights into effective storytelling, user interaction, and puzzle design.
Programming Techniques: Understanding of C++ programming, particularly in the areas of object-oriented programming (OOP), STL containers (like vectors and maps), and smart pointers (like `std::shared_ptr`).
Design Decisions
Narrative-Driven Gameplay: Emphasized storytelling and character interactions to capture the essence of the original novels but also making few changes for game simplicity and making it more clear and fun for the user. 
Modular Design: Used classes to represent different aspects of the game (e.g., `Character`, `Item`, `Inventory`, `Control`) for better code organization and maintainability.
Flexibility and Extensibility: Designed the game to be easily extendable with new characters, items, and locations, allowing for future updates and expansions.

Challenges and Solutions
Character Interactions: Ensuring interactions were meaningful and affected the storyline. Used a combination of boolean flags and points to track player choices and outcomes. It was quite challenging to handle friendly and enemy interactions as well as create a unique task such as play chess with specific character. Overall, it was difficult to maintain the game flow and keeping the code organized and without any errors. After many errors solving and going back and forth with small issues encountering in the game, I was able to create simple but effective character interactions throughout the game. 
Combat Mechanics: Balancing combat to make it challenging but fair. Implemented turn-based combat with adjustable health and attack power for characters. With the enemy character interactions, it was important to add the enemy activation depending on what item the user may pick up. To handle such an interaction with the enemy was quite hard to follow through and keep it error free. For example, few of the errors I encountered were:  the function not working at all, activation had bugs, fight or flee in infinite loop etc, but with extensive tests and reading each line of the code thoroughly with extensive understanding of the design of the game, helped over come the challenges. 
 Inventory Management: Designing an intuitive inventory system that allowed players to easily manage items. Utilized vectors and smart pointers to handle dynamic item lists. This was also a bit challenging at first to be able to use the pointers and handle the items in the inventory. But with through understanding of the concepts itself and the code design I was able to resolve the issues. 
User Commands: Processing and interpreting user commands accurately. Implemented string manipulation functions (`trim`, `toLower`) to handle various input formats. This was also difficult to organize and put up with all the interactions of the user to guarantee a smooth game flow. 

Testing and Quality Assurance
Unit Testing: Tested individual methods and classes to ensure they functioned as expected. This included methods for adding/removing items, character interactions, and command processing.
Playtesting: Conducted playtesting sessions to gather feedback on gameplay, difficulty, and user experience. Adjusted game elements based on player feedback.
Debugging: Used debugging tools and techniques to identify and fix issues. This included fixing bugs related to character recognition, item handling, and combat loops.

Future Enhancements
Additional Content: Adding more characters, items, and locations to expand the game world.
Enhanced Puzzles: Creating more complex and challenging puzzles to increase gameplay depth.
More Interactive: making it more interactive so the user can conversate with each character, use of different items in different tasks. 
I think I have created a great basic yet complex Alice in the Wonderland game, therefore with the current code and files I am confident I can make future enhancements if time was not in the equation. 
Conclusion
The "Alice in Wonderland" text-based adventure game offers players an immersive and interactive experience inspired by Lewis Carroll's beloved stories. Through careful design, research, and development, the game captures the whimsical nature of Wonderland while providing engaging gameplay, meaningful character interactions, and challenges. This design document outlines the key elements, classes, and design decisions that contribute to the game's unique and enjoyable experience.
