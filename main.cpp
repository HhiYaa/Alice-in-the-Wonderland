//Assignment 4
/* 
 Title: A4.cpp
 Description: Alice in the wonderland Text bAsed Game 
 Date: June 1, 2024
 Author: Hiya Patel
 Version: 1.0
 Copyright: 2024 Hiya Patel
*/
/*
/*
DOCUMENTATION

Program Purpose:
    This program demonstrates a text-based game inspired by the "Alice in Wonderland" storyline.
    It covers all the objectives of all the topics we have learned so far.

Compile (assuming Cygwin is running): g++ -o output_executable main.cpp Action.cpp Character.cpp Control.cpp Inventory.cpp Item.cpp Location.cpp
Execution (assuming Cygwin is running): ./output_executable 

Notes: 
    - Ensure all source files (main.cpp, Action.cpp, Character.cpp, Control.cpp, Inventory.cpp, Item.cpp, Location.cpp) are in the same directory.
    - Make sure to have the necessary Cygwin setup to compile and run the program.
    - The game involves character interactions, item handling, and navigating through various locations inspired by the "Alice in Wonderland" story.

Classes:
    - Action: Handles different actions that can be performed in the game.
    - Character: Represents the player and other characters in the game.
    - Control: Manages the game flow and user inputs.
    - Inventory: Manages items collected by the player.
    - Item: Represents items in the game.
    - Location: Represents different locations in the game.

Variables:
    - Each class has its own set of member variables. For example:
        - Character class: name, health, inventory, current location, etc.
        - Item class: itemName, itemDescription, itemEffect, etc.
        - Location class: locationName, description, itemsInLocation, connectedLocations, etc.
*/

/*
TEST PLAN

1. Test Compilation and Execution
    - Ensure the program compiles without errors using the provided compile command.
    - Run the executable to ensure it starts without runtime errors.

2. Test Navigation Commands
    - Input commands like 'go north', 'go south', 'go east', 'go west'.
    - Verify that the player moves to the correct locations and receives the appropriate location descriptions.

3. Test Item Handling
    - Test commands to pick up and drop items (e.g., 'take key', 'drop key').
    - Verify that items are correctly added to and removed from the inventory.

4. Test Character Interactions
    - Test interactions with non-player characters (NPCs).
    - Verify that conversations and interactions occur as expected.

5. Test Combat System
    - Engage in combat with enemy characters.
    - Verify that combat mechanics (attacking, health deduction) work correctly.

6. Test Inventory Management
    - Check inventory contents and use items (e.g., 'check inventory', 'use potion').
    - Verify that the inventory displays correct contents and items are used properly.

7. Test Game Flow Control
    - Test game start, pause, resume, and end functionalities.
    - Verify that the game flow is controlled as expected based on user inputs.

8. Test Edge Cases
    - Input invalid commands and verify error handling (e.g., 'fly north', 'eat sword').
    - Test boundary conditions such as empty inventory, no connected locations, etc.
*/

/*
TEST PLAN

1. Test Compilation and Execution
    a. Ensure the program compiles without errors.
       - Command: g++ -o output_executable main.cpp Action.cpp Character.cpp Control.cpp Inventory.cpp Item.cpp Location.cpp
       - Expected Result: Compilation completes without errors.
    b. Run the executable to ensure it starts without runtime errors.
       - Command: ./output_executable
       - Expected Result: The game starts and displays the initial game message or menu.

2. Test Navigation Commands
    a. Test basic movement commands.
       - Command: 'go north'
       - Expected Result: Player moves to the location north of the current one and receives the appropriate description.
       - Command: 'go south'
       - Expected Result: Player moves to the location south of the current one and receives the appropriate description.
       - Command: 'go east'
       - Expected Result: Player moves to the location east of the current one and receives the appropriate description.
       - Command: 'go west'
       - Expected Result: Player moves to the location west of the current one and receives the appropriate description.
    b. Test invalid movement commands.
       - Command: 'go up'
       - Expected Result: Error message indicating the direction is invalid.

3. Test Item Handling
    a. Test picking up items.
       - Command: 'take Rock'
       - Expected Result: Key is added to the player's inventory and removed from the location.
    b. Test picking up an item not in the location.
       - Command: 'take sword' (when there is no sword in the current location)
       - Expected Result: Error message indicating the item is not present.
    d. Test enemy activation when picking up certain items.
       - Command: 'take sword' (when there is no sword in the inventory)
       - Expected Result: You take the Sword.
            A Goblin appears in Mad Hatter's Tea Party!
            You encounter Goblin! They look hostile.
            Do you want to fight or flee? (fight/flee): 

4. Test Character Interactions
    a. Test interacting to NPCs.
       - Command: 'interact white rabbit'
       - Expected Result: The game displays a conversation with the rabbit.
    b. Test giving items to NPCs.
       - Command: 'give key to rabbit'
       - Expected Result: Key is removed from the player's inventory and the rabbit acknowledges the receipt.
    c. Test invalid interactions.
       - Command: 'talk to tree'
       - Expected Result: Error message indicating the interaction is invalid.

5. Test Combat System
    a. Test engaging in combat.
       - Command: 'attack goblin'
       - Expected Result: The player and the goblin engage in combat, with appropriate health deductions displayed.
    b. Test using items in combat.
       - Command: 'use potion'
       - Expected Result: The player uses the potion, regaining health or other effects as applicable.
    c. Test combat with no enemies.
       - Command: 'attack'
       - Expected Result: Error message indicating there are no enemies to attack.

6. Test Inventory Management
    a. Check inventory contents.
       - Command: 'check inventory'
       - Expected Result: The game displays a list of items currently in the player's inventory.
    b. Use items from the inventory.
       - Command: 'use key'
       - Expected Result: The key is used to unlock a door or another appropriate action is performed.
    c. Test inventory capacity (if applicable).
       - Add items until the inventory is full.
       - Expected Result: Error message indicating the inventory is full when attempting to add another item.

7. Test Game Flow Control
    a. Test game start.
       - Command: Start the game.
       - Expected Result: The game initializes and displays the starting location and initial message.
    b. Test pausing the game.
       - Command: 'pause'
       - Expected Result: The game pauses and displays a pause message.
    c. Test resuming the game.
       - Command: 'resume'
       - Expected Result: The game resumes from where it was paused.
    d. Test ending the game.
       - Command: 'quit'
       - Expected Result: The game ends and displays an exit message.
    e. Test saving the game (if applicable).
       - Command: 'save'
       - Expected Result: The game state is saved to a file.
    f. Test loading the game (if applicable).
       - Command: 'load'
       - Expected Result: The game state is loaded from a file.

8. Test Edge Cases
    a. Test inputting invalid commands.
       - Command: 'fly north'
       - Expected Result: Error message indicating the command is invalid.
    b. Test boundary conditions.
       - Navigate to a location with no connected locations in one direction.
       - Expected Result: Error message indicating the player cannot move in that direction.
    c. Test empty inventory interactions.
       - Command: 'drop'
       - Expected Result: Error message indicating there is no item to drop.
    d. Test interactions with no connected NPCs.
       - Command: 'talk'
       - Expected Result: Error message indicating there is no one to talk to.
    e. Test using non-existent items.
       - Command: 'use invisible cloak'
       - Expected Result: Error message indicating the item does not exist.
*/

/*
TEST PLAN
Case 1: Normal Game Flow
Welcome to Wonderland!
Your goal is to reach the Queen's Castle and win the game.
Along the way, you can interact with characters, collect items, and perform actions to earn points.
Your ultimate goal is to reach the Queen's Castle with amximum Points you can get!
Use commands like 'go north', 'go south', 'look', 'inventory', 'take [item]','fight [character]', and 'interact [character]'.
Hint: eneter the names of item and characters exctly the way it was mentioned in the output.

White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Cheshire Cat -  for location: Enchanted Garden
A grinning cat that can disappear and reappear - friendly. for location: Enchanted Garden
Goblin -  for location: Enchanted Garden
Attacks you out of nowhere - enemy for location: Enchanted Garden
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party    
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
You are at the rabbit hole and ready for the adventure.
Exits: south
White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Characters:
White Rabbit: A white rabbit with a pocket watch - looks anxious

Items: 
Food:
Flashlight:
Rock:
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.

> take Rock
You take the Rock.
You now have 10 points.
> take Food
You take the Food.
You now have 20 points.
> take Flashlight
You take the Flashlight.
You now have 30 points.
> interact White Rabbit
Interacting with White Rabbit
You now have 50 points.
> go south
You are in a hallway lined with doors.
Exits: west east south
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Characters:
Caterpillar: The Caterpillar instructs you on how to eat the mushroom

Items:
Sword:
Drink Me Potion:
Cake:
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.

You now have 60 points.
> interact Caterpillar
Interacting with Caterpillar
You now have 80 points.
> take Cake 
You take the Cake.
You now have 90 points.
> take Sword
You take the Sword.
You now have 100 points.
A Goblin appears in!
You encounter Goblin! They look hostile.
Do you want to fight or flee? (fight/flee): fight
You fight Goblin with your Sword and win!
You now have 120 points.
Great! You may continue your adventure.
> go east
You are in an enchanted garden filled with magical flora.
Exits: south west
Cheshire Cat -  for location: Enchanted Garden
A grinning cat that can disappear and reappear - friendly. for location: Enchanted Garden
Goblin -  for location: Enchanted Garden
Attacks you out of nowhere - enemy for location: Enchanted Garden
Characters:
Cheshire Cat: A grinning cat that can disappear and reappear

Items:
Tea:
Dormouse:
Golden Key:A golden key that opens a special door.
Mushroom:Mushrooms lying on the ground.
Cheshire Cat's Smile:The smile of the Cheshire Cat, which gives you hints.
Gold Jewelry:Shiny gold jewelry.
Golden Key:A golden key that opens a special door.
Mushroom:Mushrooms lying on the ground.
Cheshire Cat's Smile:The smile of the Cheshire Cat, which gives you hints.
Gold Jewelry:Shiny gold jewelry.

You now have 130 points.
> take Mushroom 
You take the Mushroom.
You now have 140 points.
> interact Goblin
There is no such character here.
> go west  
You are at the Mad Hatter's Tea Party.
Exits: south east
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party    
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Characters:
Mad Hatter: A quirky character with a penchant for tea
Dormouse: A sleepy mouse at the tea party
Goblin: Attacks you out of nowhere

Items:
Mushroom:
Gold Jewelry:
Cheshire Cat's Smile:
Golden Key:
Dormouse:A dormouse is sleeping at the Tea Party.
Tea:Villagers offering tea to drink.
Dormouse:A dormouse is sleeping at the Tea Party.
Tea:Villagers offering tea to drink.

You now have 150 points.
> take Mushroom 
You take the Mushroom.
You now have 160 points.
> interact Mad Hatter
Interacting with Mad Hatter
You now have 180 points.
> take Tea
You take the Tea.
You now have 190 points.
> go south
You are in the Queen's rose garden.
Exits: south
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
Characters:
Queen: The Queen of Hearts, who loves playing chess and is obsessed with beheading

Items:
Dormouse:
ChessGame:

You now have 200 points.
> interact Queen
You encounter the Queen. Do you want to play along chess with her or challenge her? Hint: Queen has bad temper.
play along 
You play chess with the queen.
You now have 300 points.
The Queen is happy with you now will let you enter the Queen's Castle!
You now have 350 points.
> go south
You are in the Queen's Castle.
There are no exits.
There are no other characters here.
Items:
Crown:
Crown:You see a shining Crown accross the room.
Crown:You see a shining Crown accross the room.

You now have 360 points.
You have won the game!
Thank you for the great adventure!
Your final score is: 360 points.

//

Case 2: Choosing Differnt Options 
Welcome to Wonderland!
Your goal is to reach the Queen's Castle and win the game.
Along the way, you can interact with characters, collect items, and perform actions to earn points.
Your ultimate goal is to reach the Queen's Castle with amximum Points you can get!
Use commands like 'go north', 'go south', 'look', 'inventory', 'take [item]','fight [character]', and 'interact [character]'.    
Hint: eneter the names of item and characters exctly the way it was mentioned in the output.

White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Cheshire Cat -  for location: Enchanted Garden
A grinning cat that can disappear and reappear - friendly. for location: Enchanted Garden
Goblin -  for location: Enchanted Garden
Attacks you out of nowhere - enemy for location: Enchanted Garden
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party    
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
You are at the rabbit hole and ready for the adventure.
Exits: south
White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Characters:
White Rabbit: A white rabbit with a pocket watch - looks anxious

Items:
Food:
Flashlight:
Rock:
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.

> take Food
You take the Food.
You now have 10 points.
> take Flashlight
You take the Flashlight.
You now have 20 points.
> interact White Rabbit
Interacting with White Rabbit
You now have 40 points.
> go south
You are in a hallway lined with doors.
Exits: west east south
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Characters:
Caterpillar: The Caterpillar instructs you on how to eat the mushroom

Items:
Sword:
Drink Me Potion:
Cake:
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.

You now have 50 points.
> take Cake 
You take the Cake.
You now have 60 points.
> interact Caterpillar
Interacting with Caterpillar
You now have 80 points.
> take Sword
You take the Sword.
You now have 90 points.
A Goblin appears in!
You encounter Goblin! They look hostile.
Do you want to fight or flee? (fight/flee): flee
You flee from Goblin but lose some points for not fighting.
You now have 70 points.
Great! You may continue your adventure.
> go west
You are at the Mad Hatter's Tea Party.
Exits: south east
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party    
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Characters:
Mad Hatter: A quirky character with a penchant for tea
Dormouse: A sleepy mouse at the tea party
Goblin: Attacks you out of nowhere

Items:
Mushroom:
Gold Jewelry:
Cheshire Cat's Smile:
Golden Key:
Dormouse:A dormouse is sleeping at the Tea Party.
Tea:Villagers offering tea to drink.
Dormouse:A dormouse is sleeping at the Tea Party.
Tea:Villagers offering tea to drink.

You now have 80 points.

//

Case 3: Different option Selection. Checking inventory, interactions, locations. 
Welcome to Wonderland!
Your goal is to reach the Queen's Castle and win the game.
Along the way, you can interact with characters, collect items, and perform actions to earn points.
Your ultimate goal is to reach the Queen's Castle with amximum Points you can get!
Use commands like 'go north', 'go south', 'look', 'inventory', 'take [item]','fight [character]', and 'interact [character]'.    
Hint: eneter the names of item and characters exctly the way it was mentioned in the output.

White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Cheshire Cat -  for location: Enchanted Garden
A grinning cat that can disappear and reappear - friendly. for location: Enchanted Garden
Goblin -  for location: Enchanted Garden
Attacks you out of nowhere - enemy for location: Enchanted Garden
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party    
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
You are at the rabbit hole and ready for the adventure.
Exits: south
White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Characters:
White Rabbit: A white rabbit with a pocket watch - looks anxious

Items:
Food:
Flashlight:
Rock:
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.

> take Rock 
You take the Rock.
You now have 10 points.
> take flashlight
There is no such item here.
> take Food 
You take the Food.
You now have 20 points.
> interact White Rabbit
Interacting with White Rabbit
You now have 40 points.
> go south
You are in a hallway lined with doors.
Exits: west east south
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Characters:
Caterpillar: The Caterpillar instructs you on how to eat the mushroom

Items:
Sword:
Drink Me Potion:
Cake:
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.

You now have 50 points.
> take Cake
You take the Cake.
You now have 60 points.
> interact catterpillar
There is no such character here.
> interact Caterpillar   
Interacting with Caterpillar
You now have 80 points.
> go east
You are in an enchanted garden filled with magical flora.
Exits: south west
Cheshire Cat -  for location: Enchanted Garden
A grinning cat that can disappear and reappear - friendly. for location: Enchanted Garden
Goblin -  for location: Enchanted Garden
Attacks you out of nowhere - enemy for location: Enchanted Garden
Characters:
Cheshire Cat: A grinning cat that can disappear and reappear

Items:
Tea:
Dormouse:
Golden Key:A golden key that opens a special door.
Mushroom:Mushrooms lying on the ground.
Cheshire Cat's Smile:The smile of the Cheshire Cat, which gives you hints.
Gold Jewelry:Shiny gold jewelry.
Golden Key:A golden key that opens a special door.
Mushroom:Mushrooms lying on the ground.
Cheshire Cat's Smile:The smile of the Cheshire Cat, which gives you hints.
Gold Jewelry:Shiny gold jewelry.

You now have 90 points.
> take Mushroom 
You take the Mushroom.
You now have 100 points.
> take Golden key
There is no such item here.
> go west
You are at the Mad Hatter's Tea Party.
Exits: south east
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party    
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Characters:
Mad Hatter: A quirky character with a penchant for tea
Dormouse: A sleepy mouse at the tea party

Items:
Mushroom:
Gold Jewelry:
Cheshire Cat's Smile:
Golden Key:
Dormouse:A dormouse is sleeping at the Tea Party.
Tea:Villagers offering tea to drink.
Dormouse:A dormouse is sleeping at the Tea Party.
Tea:Villagers offering tea to drink.

You now have 110 points.
> interact Goblin
There is no such character here.
> take Tea
You take the Tea.
You now have 120 points.
> take Mushroom 
You take the Mushroom.
You now have 130 points.
> go south 
You are in the Queen's rose garden.
Exits: south
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
Characters:
Queen: The Queen of Hearts, who loves playing chess and is obsessed with beheading

Items:
Dormouse:
ChessGame:

You now have 140 points.
> go south
You must play chess with the queen before you can enter the Queen's Castle.
> interact Queen 
You encounter the Queen. Do you want to play along chess with her or challenge her? Hint: Queen has bad temper.
challenge 
The Queen gets Mad and sends you to the courtroom!
You now have 120 points.
You are in the courtroom with the King and Queen.
Oh No! You have lost the game!
Thank you for the great adventure!
Your final score is: 120 points.

Case 4: Bad Input handlings 
Welcome to Wonderland!
Your goal is to reach the Queen's Castle and win the game.
Along the way, you can interact with characters, collect items, and perform actions to earn points.
Your ultimate goal is to reach the Queen's Castle with amximum Points you can get!
Use commands like 'go north', 'go south', 'look', 'inventory', 'take [item]','fight [character]', and 'interact [character]'.    
Hint: eneter the names of item and characters exctly the way it was mentioned in the output.

White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Cheshire Cat -  for location: Enchanted Garden
A grinning cat that can disappear and reappear - friendly. for location: Enchanted Garden
Goblin -  for location: Enchanted Garden
Attacks you out of nowhere - enemy for location: Enchanted Garden
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party    
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
You are at the rabbit hole and ready for the adventure.
Exits: south
White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Characters:
White Rabbit: A white rabbit with a pocket watch - looks anxious

Items:
Food:
Flashlight:
Rock:
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.

> take Rock 
You take the Rock.
You now have 10 points.
> take Food
You take the Food.
You now have 20 points.
> interact White Rabbit 
Interacting with White Rabbit
You now have 40 points.
> take Rock 
You take the Rock.
You now have 50 points.
> go south
You are in a hallway lined with doors.
Exits: west east south
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Characters:
Caterpillar: The Caterpillar instructs you on how to eat the mushroom

Items:
Sword:
Drink Me Potion:
Cake:
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.

You now have 60 points.
> take Cake 
You take the Cake.
You now have 70 points.
> interact caterpillar
Interacting with Caterpillar
You now have 90 points.
> take Sword
You take the Sword.
You now have 100 points.
A Goblin appears in!
You encounter Goblin! They look hostile.
Do you want to fight or flee? (fight/flee): flee
You flee from Goblin but lose some points for not fighting.
You now have 80 points.
Great! You may continue your adventure.
> go west
You are at the Mad Hatter's Tea Party.
Exits: south east
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party    
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Characters:
Mad Hatter: A quirky character with a penchant for tea
Dormouse: A sleepy mouse at the tea party
Goblin: Attacks you out of nowhere

Items:
Mushroom:
Gold Jewelry:
Cheshire Cat's Smile:
Golden Key:
Dormouse:A dormouse is sleeping at the Tea Party.
Tea:Villagers offering tea to drink.
Dormouse:A dormouse is sleeping at the Tea Party.
Tea:Villagers offering tea to drink.

You now have 90 points.
> take Tea
You take the Tea.
You now have 100 points.
> i
Items in your inventory:
- Rock
- Food
- Rock A rock that might come in handy.
- Cake
- Sword
- Tea Villagers offering tea to drink.
> inventory
Items in your inventory:
- Rock
- Food
- Rock A rock that might come in handy.
- Cake
- Sword
- Tea Villagers offering tea to drink.
> interact Mad Hatter
Interacting with Mad Hatter
You now have 120 points.
> go south
You are in the Queen's rose garden.
Exits: south
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
Characters:
Queen: The Queen of Hearts, who loves playing chess and is obsessed with beheading

Items:
Dormouse:
ChessGame:

You now have 130 points.
> interact Queen
You encounter the Queen. Do you want to play along chess with her or challenge her? Hint: Queen has bad temper.
Play 
You play chess with the queen.
You now have 230 points.
The Queen is happy with you now will let you enter the Queen's Castle!
You now have 280 points.
> go south
You are in the Queen's Castle.
There are no exits.
There are no other characters here.
Items:
Crown:
Crown:You see a shining Crown accross the room.
Crown:You see a shining Crown accross the room.

You now have 290 points.
You have won the game!
Thank you for the great adventure!
Your final score is: 290 points.

Bad case: Input Handlings 
Welcome to Wonderland!
Your goal is to reach the Queen's Castle and win the game.
Along the way, you can interact with characters, collect items, and perform actions to earn points.
Your ultimate goal is to reach the Queen's Castle with amximum Points you can get!
Use commands like 'go north', 'go south', 'look', 'inventory', 'take [item]','fight [character]', and 'interact [character]'.    
Hint: eneter the names of item and characters exctly the way it was mentioned in the output.

White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Cheshire Cat -  for location: Enchanted Garden
A grinning cat that can disappear and reappear - friendly. for location: Enchanted Garden
Goblin -  for location: Enchanted Garden
Attacks you out of nowhere - enemy for location: Enchanted Garden
Mad Hatter -  for location: Mad Hatter's Tea Party
A quirky character with a penchant for tea is hosting a perpetual tea party. - friendly. for location: Mad Hatter's Tea Party
Dormouse -  for location: Mad Hatter's Tea Party
A sleepy mouse at the tea party - friendly. for location: Mad Hatter's Tea Party
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
You are at the rabbit hole and ready for the adventure.
Exits: south
White Rabbit -  for location: Rabbit Hole
A white rabbit with a pocket watch -  looks anxious for location: Rabbit Hole
Characters:
White Rabbit: A white rabbit with a pocket watch - looks anxious

Items:
Food:
Flashlight:
Rock:
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.
Food:Some food to collect.
Flashlight:A flashlight to help you see in the dark.
Rock:A rock that might come in handy.

> 67
I don't understand that command.
> 97
I don't understand that command.
> hidhs
I don't understand that command.
> take rock
There is no such item here. Or you may Try Agan! Type the exact way it was displayed for you.
> take Rock
You take the Rock.
You now have 10 points.
> inventory
Items in your inventory:
- Rock
> go south
You are in a hallway lined with doors.
Exits: west east south
Caterpillar -  for location: Hallway of Doors
The Caterpillar instructs you on how to eat the mushroom - friendly. for location: Hallway of Doors
Cheshire Cat -  for location: Hallway of Doors
A grinning cat that can appear and disappear at times - friendly. for location: Hallway of Doors
Thief -  for location: Hallway of Doors
Tries to steal your expensive item - enemy for location: Hallway of Doors
Characters:
Caterpillar: The Caterpillar instructs you on how to eat the mushroom

Items:
Sword:
Drink Me Potion:
Cake:
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.
Drink Me Potion:A potion that makes you shrink.
Eat Me Cake:A cake that makes you grow.
Sword:A sword for safety.

You now have 20 points.
> take Cake 
You take the Cake.
You now have 30 points.
> take Sword
You take the Sword.
You now have 40 points.
A Goblin appears in!
You encounter Goblin! They look hostile.
Do you want to fight or flee? (fight/flee): flee
You flee from Goblin but lose some points for not fighting.
You now have 20 points.
Great! You may continue your adventure.
> go south
You are in the Queen's rose garden.
Exits: south
Queen -  for location: Queen's Rose Garden
The Queen of Hearts -  who loves playing chess and is obsessed with beheading for location: Queen's Rose Garden
Characters:
Queen: The Queen of Hearts, who loves playing chess and is obsessed with beheading

Items:
Dormouse:
ChessGame:

You now have 30 points.
> interact hednj
There is no such character here.
> interact Hearts
There is no such character here.
> interact Queen
You encounter the Queen. Do you want to play along chess with her or challenge her? Hint: Queen has bad temper.
play      
You play chess with the queen.
You now have 130 points.
The Queen is happy with you now will let you enter the Queen's Castle!
You now have 180 points.
> go south
You are in the Queen's Castle.
There are no exits.
There are no other characters here.
Items:
Crown:
Crown:You see a shining Crown accross the room.
Crown:You see a shining Crown accross the room.

You now have 190 points.
You have won the game!
Thank you for the great adventure!
Your final score is: 190 points.
*/

// main.cpp
#include "Control.h"

int main() {
    Control control;
    control.run();
    return 0;
}

