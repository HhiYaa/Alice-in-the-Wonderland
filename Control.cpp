#include "Control.h"
#include "Location.h"
#include "Item.h"
#include "Character.h"
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <algorithm>


// Constructor initializes the game and sets initial points to 0
Control::Control() : points(0) {
    initializeGame();
}

// Main game loop, reads commands from the user until the game ends
void Control::run() {
    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        if (processCommand(command)) {
            break;
        }
    }
}

// Adds points to the player's score and displays the current score
void Control::addPoints(int points) {
    this->points += points;
    std::cout << "You now have " << this->points << " points." << std::endl;
}

// Initializes the game, sets up locations, characters, items, and starting conditions
void Control::initializeGame() {
    displayGameGuide();
    inventory = std::make_shared<Inventory>();

    // Define characters
    auto whiteRabbit = std::make_shared<Character>("White Rabbit", "A white rabbit with a pocket watch - looks anxious", true, 100, 10);
    auto madHatter = std::make_shared<Character>("Mad Hatter", "A quirky character with a penchant for tea", true, 100, 10);
    auto dormouse = std::make_shared<Character>("Dormouse", "A sleepy mouse at the tea party", true, 100, 5);
    auto queen = std::make_shared<Character>("Queen", "The Queen of Hearts, who loves playing chess and is obsessed with beheading", true, 200, 50);
    auto cheshireCat = std::make_shared<Character>("Cheshire Cat", "A grinning cat that can disappear and reappear", true, 100, 20);
    auto goblin = std::make_shared<Character>("Goblin", "Attacks you out of nowhere, enemy", false, 100, 30);
    auto caterpillar = std::make_shared<Character>("Caterpillar", "The Caterpillar instructs you on how to eat the mushroom", true, 100, 10);
    auto thief = std::make_shared<Character>("Thief", "Tries to steal your expensive item, enemy", false, 100, 20);


    // Create locations
    auto rabbitHole = std::make_shared<Location>("Rabbit Hole", "You are at the rabbit hole and ready for the adventure.");
    auto hallwayOfDoors = std::make_shared<Location>("Hallway of Doors", "You are in a hallway lined with doors.");
    auto enchantedGarden = std::make_shared<Location>("Enchanted Garden", "You are in an enchanted garden filled with magical flora.");
    auto madHattersTeaParty = std::make_shared<Location>("Mad Hatter's Tea Party", "You are at the Mad Hatter's Tea Party.");
    auto queensRoseGarden = std::make_shared<Location>("Queen's Rose Garden", "You are in the Queen's rose garden.");
    auto QueensCastle = std::make_shared<Location>("Queen's Castle", "You are in the Queen's Castle.");
    auto Courtroom = std::make_shared<Location>("Courtroom", "You are being sent to the Courtroom.");

    // Add items to locations
    rabbitHole->addItem(std::make_shared<Item>("Food", itemDesc["Food"]));
    rabbitHole->addItem(std::make_shared<Item>("Flashlight", itemDesc["Flashlight"]));
    rabbitHole->addItem(std::make_shared<Item>("Rock", itemDesc["Rock"]));

    hallwayOfDoors->addItem(std::make_shared<Item>("Sword", itemDesc["Sword"]));
    hallwayOfDoors->addItem(std::make_shared<Item>("Drink Me Potion", itemDesc["Drink Me Potion"]));
    hallwayOfDoors->addItem(std::make_shared<Item>("Cake", itemDesc["Cake"]));

    madHattersTeaParty->addItem(std::make_shared<Item>("Mushroom", itemDesc["Mushroom"]));
    madHattersTeaParty->addItem(std::make_shared<Item>("Gold Jewelry", itemDesc["Gold Jewelry"]));
    madHattersTeaParty->addItem(std::make_shared<Item>("Cheshire Cat's Smile", itemDesc["Cheshire Cat's Smile"]));
    madHattersTeaParty->addItem(std::make_shared<Item>("Golden Key", itemDesc["Golden Key"]));

    enchantedGarden->addItem(std::make_shared<Item>("Tea", itemDesc["Tea"]));
    enchantedGarden->addItem(std::make_shared<Item>("Dormouse", itemDesc["Dormouse"]));
   
    queensRoseGarden->addItem(std::make_shared<Item>("Dormouse", itemDesc["Dormouse"]));
    queensRoseGarden->addItem(std::make_shared<Item>("ChessGame", itemDesc["ChessGame"]));

    QueensCastle->addItem(std::make_shared<Item>("Crown",itemDesc["Crown"]));

    // Link locations with exits
    rabbitHole->setExit("south", hallwayOfDoors);
    hallwayOfDoors->setExit("south", queensRoseGarden);
    hallwayOfDoors->setExit("east", enchantedGarden);
    hallwayOfDoors->setExit("west", madHattersTeaParty);
    madHattersTeaParty->setExit("east", enchantedGarden);
    madHattersTeaParty->setExit("south", queensRoseGarden);
    enchantedGarden->setExit("west", madHattersTeaParty);
    enchantedGarden->setExit("south", queensRoseGarden);
    queensRoseGarden->setExit("south", QueensCastle);

    // Load characters and items from files into locations 
    rabbitHole->loadCharactersFromFile("characters.txt");
    rabbitHole->loadItemsFromFile("items.txt");

    hallwayOfDoors->loadCharactersFromFile("characters.txt");
    hallwayOfDoors->loadItemsFromFile("items.txt");

    enchantedGarden->loadCharactersFromFile("characters.txt");
    enchantedGarden->loadItemsFromFile("items.txt");

    madHattersTeaParty->loadCharactersFromFile("characters.txt");
    madHattersTeaParty->loadItemsFromFile("items.txt");

    queensRoseGarden->loadCharactersFromFile("characters.txt");
    queensRoseGarden->loadItemsFromFile("items.txt");

    QueensCastle->loadCharactersFromFile("characters.txt");
    QueensCastle->loadItemsFromFile("items.txt");

    // Add locations to the map
    locations["Rabbit Hole"] = rabbitHole;
    locations["Hallway of Doors"] = hallwayOfDoors;
    locations["Enchanted Garden"] = enchantedGarden;
    locations["Mad Hatter's Tea Party"] = madHattersTeaParty;
    locations["Queen's Rose Garden"] = queensRoseGarden;
    locations["Queen's Castle"] = QueensCastle;
    locations["Courtroom"] = Courtroom;

    // Add characters to locations
    rabbitHole->addCharacter(whiteRabbit);
    madHattersTeaParty->addCharacter(madHatter);
    madHattersTeaParty->addCharacter(dormouse);
    queensRoseGarden->addCharacter(queen);
    enchantedGarden->addCharacter(cheshireCat);
    //enchantedGarden->addCharacter(goblin);
    hallwayOfDoors->addCharacter(caterpillar);
    //hallwayOfDoors->addCharacter(thief);

    // Set the starting location
    currentLocation = rabbitHole;
    visitedLocations.insert(currentLocation->getName()); // Mark initial location as visited

    // displayGameGuide();
    currentLocation->describe();

}

// Displays the game guide with instructions and objectives
void Control::displayGameGuide() {
    std::cout << std::endl;
    std::cout << "Welcome to Wonderland!" << std::endl;
    std::cout << "Your goal is to reach the Queen's Castle and win the game." << std::endl;
    std::cout << "Along the way, you can interact with characters, collect items, and perform actions to earn points." << std::endl;
    std::cout << "Your ultimate goal is to reach the Queen's Castle with amximum Points you can get!" << std::endl;
    std::cout << "Use commands like 'go north', 'go south', 'look', 'inventory', 'take [item]','fight [character]', and 'interact [character]'." << std::endl;
    std::cout << "Hint: eneter the names of item and characters exctly the way it was mentioned in the output." << std::endl;
    std::cout << std::endl;
}

// Interacts with a character in the current location
void Control::interactCharacter(const std::string& characterName) {
    if (currentLocation->hasCharacter(characterName)) {
        auto character = currentLocation->getCharacter(characterName);
        character->interact();
        addPoints(50);
    } else {
        std::cout << "There is no such character here." << std::endl;
    }
}

// Handles interaction with an enemy character
void Control::handleEnemyInteraction(const  std::shared_ptr<Character>& enemy) {
    std::cout << "You encounter " << enemy->getName() << "! They look hostile." << std::endl;
    std::cout << "Do you want to fight or flee? (fight/flee): ";
    std::string choice;
    std::cin >> choice;
    std::cin.ignore(); 

    if (choice == "fight") {
        if (inventory->hasItem("Sword")) {
            std::cout << "You fight " << enemy->getName() << " with your Sword and win!" << std::endl;
            addPoints(20); // Award points for defeating the enemy
            currentLocation->removeCharacter(enemy->getName());
        } else {
            std::cout << "You don't have a weapon to fight " << enemy->getName() << "." << std::endl;
            std::cout << "You get injured and lose points." << std::endl;
            addPoints(-35); // Deduct points for losing the fight
        }
    } else if (choice == "flee") {
        std::cout << "You flee from " << enemy->getName() << " but lose some points for not fighting." << std::endl;
        addPoints(-20); // Deduct points for fleeing
        currentLocation->removeCharacter(enemy->getName());
    } else {
        std::cout << "Invalid choice. You get injured and lose points." << std::endl;
        addPoints(-10); // Deduct points for invalid choice
        // currentLocation->removeCharacter(enemy->getName()); 
    }
    currentLocation->removeCharacter(enemy->getName());
    std::cout << "Great! You may continue your adventure." << std::endl;

}


// Handles interaction with a character in a fight
void Control::fightCharacter(const std::string& characterName) {
    if (currentLocation->hasCharacter(characterName)) {
        auto character = currentLocation->getCharacter(characterName);
        if (!character->isFriendly()) {
           // Combathandle(character);
           handleEnemyInteraction(character);
        } else {
            std::cout << "You can't fight a friendly character." << std::endl;
        }
    } else {
        std::cout << "There is no such character here." << std::endl;
    }
}


// Helper function to trim leading and trailing whitespace from a string
std::string Control::trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }
    auto end = str.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

// Helper function to convert a string to lowercase
std::string Control::toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Processes player commands and returns true if the game should end
bool Control::processCommand(const std::string& command) {
    std::istringstream stream(command);
    std::string action;
    stream >> action;

    // Check if the current location is Queen's Castle
    if (currentLocation->getName() == "Queen's Castle") {
        std::cout << "You have won the game!" << std::endl;
        std::cout << "Thank you for the great adventure!" << std::endl;
        std::cout << "Your final score is: " << this->points << " points." << std::endl;
        return true;
    }

    if (action == "quit") {
        std::cout << "Thank you for the great adventure!" << std::endl;
        std::cout << "Your final score is: " << this->points << " points." << std::endl;
        return true;
    } else if (action == "look") {
        currentLocation->describe();
    // } else if (action == "interact") {

    } else if (action == "go") {
        std::string direction;
        stream >> direction;
        std::transform(direction.begin(), direction.end(), direction.begin(), ::tolower); // Convert direction to lowercase
        if (currentLocation->hasExit(direction)) {
            auto nextLocation = currentLocation->getExit(direction);

             if (nextLocation->getName() == "Queen's Castle" && !hasPlayedChessWithQueen) {
                std::cout << "You must play chess with the queen before you can enter the Queen's Castle." << std::endl;
                return false;
            }

            currentLocation = currentLocation->getExit(direction);
            currentLocation->describe();

                        // Add points for visiting a new location
            if (visitedLocations.find(currentLocation->getName()) == visitedLocations.end()) {
                visitedLocations.insert(currentLocation->getName());
                addPoints(10); // Award 10 points for visiting a new location
            }

            // Check again if the new location is Queen's Castle after moving
            if (currentLocation->getName() == "Queen's Castle") {
                std::cout << "You have won the game!" << std::endl;
                std::cout << "Thank you for the great adventure!" << std::endl;
                std::cout << "Your final score is: " << this->points << " points." << std::endl;
                return true;
            }
        } else {
            std::cout << "You can't go that way." << std::endl;
        }
        } else if (action == "take") {
            std::string itemName;
            stream >> itemName;
            

                if (currentLocation->hasItem(itemName)) {
                    auto item = currentLocation->removeItem(itemName);
                    inventory->addItem(item);
                    std::cout << "You take the " << itemName << "." << std::endl;
                    addPoints(10);
                    handleItemPickup(itemName);
                    currentLocation->activateEnemiesBasedOnItem(itemName);

                } else {
                    std::cout << "There is no such item here. Or you may Try Agan! Type the exact way it was displayed for you." << std::endl;
                }
        } else if ((action == "inventory") || (action == "i") || (action == "Inventory")) {
                inventory->listItems();
        } else if (action == "interact") {
        std::string characterName;
        std::getline(stream, characterName);

        // Trim leading and trailing spaces and convert to lowercase
        characterName = toLower(trim(characterName));
            
            if ((characterName == "queen")){
           // std::cout << "You encounter the Queen. Do you want to play along chess with her or challenge her?" << std::endl;
            interactWithQueen();
            } else {
            bool characterFound = false;

                for (const auto& character : currentLocation->getAllCharacters()) {
                    if (toLower(trim(character->getName())) == characterName) {
                        character->interact();
                        addPoints(20);

                        if (character->isEnemy()) {
                            handleEnemyInteraction(character);
                            return true; 
                        }

                        characterFound = true;
                        break;
                    }
                }

        if (!characterFound) {
            std::cout << "There is no such character here." << std::endl;
        }
     }
    } else if (action == "fight") {
        std::string characterName;
        stream >> characterName;
        //std::transform(characterName.begin(), characterName.end(), characterName.begin(), ::tolower); // Convert character name to lowercase
        fightCharacter(characterName);
    } else {
        std::cout << "I don't understand that command." << std::endl;
    }
    if (currentLocation->hasEnemies()) {
        for (const auto& enemy : currentLocation->getEnemies()) {
            handleEnemyInteraction(enemy);
        }
    }
return false;
}    
    

//Handles interaction with the Queen 
void Control::interactWithQueen() {
    std::cout << "You encounter the Queen. Do you want to play along chess with her or challenge her? Hint: Queen has bad temper." << std::endl;
    std::string action;
    std::getline(std::cin, action);

     // Convert action to lowercase to make the comparison case-insensitive
    action = toLower(trim(action));

        if ((action == "play along")||(action == "play")) {
            playChessWithQueen();
       
            std::cout << "The Queen is happy with you now will let you enter the Queen's Castle!" << std::endl;
            addPoints(50);

        } else if ((action == "challenge")||(action == "challenge Queen") || (action == "Challenge")) {
            std::cout << "The Queen gets Mad and sends you to the courtroom!" << std::endl;
            // Handle loss scenario
            addPoints(-20); // Example point deduction for losing
            interactInCourtroom();

        } else {
        std::cout << "I either do not undertand ypur command or you chose not to play chess with the Queen." << std::endl;
   
        }
}

//Handles interaction with the Queen to play Chess 
//Makes sure that user played chess with the Queen
bool Control::playChessWithQueen() {
    std::cout << "You play chess with the queen." << std::endl;
    addPoints(100); // Award points for playing chess with the queen
    hasPlayedChessWithQueen = true;
    //currentLocation->describe();
    return true;
}

// Handle courtroom interaction
void Control::interactInCourtroom() {
    std::cout << "You are in the courtroom with the King and Queen." << std::endl;
    // Handle interaction logic here
    //addPoints(-20); // Example point deduction for courtroom interaction
    std::cout << "Oh No! You have lost the game!" << std::endl;
    std::cout << "Thank you for the great adventure!" << std::endl;
    std::cout << "Your final score is: " << this->points << " points." << std::endl;
    exit(0);
    //return false;
    
}

void Control::handleItemPickup(const std::string& itemName) {
    if (itemName == "Gold Jewelry") {
        auto thief = std::make_shared<Character>("Thief", "Tries to steal your expensive item", false, 100, 20);
        auto nearbyLocation = getNextLocation();
        if (nearbyLocation) {
            nearbyLocation->addCharacter(thief);
            std::cout << "A Thief appears in !" << std::endl;
        }
    } else if (itemName == "Sword") {
        auto goblin = std::make_shared<Character>("Goblin", "Attacks you out of nowhere", false, 150, 30);
        auto nearbyLocation = getNextLocation();
        if (nearbyLocation) {
            nearbyLocation->addCharacter(goblin);
            std::cout << "A Goblin appears in!" << std::endl;
        }
    }
}

std::shared_ptr<Location> Control::getNextLocation() {
    for (const auto& exit : currentLocation->getExits()) {
        if (!visitedLocations.count(exit.second->getName())) {
            return exit.second;
        }
    }
    return nullptr;
}


