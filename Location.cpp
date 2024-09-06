#include "Location.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Character.h"

// Constructor implementation for the Location class
Location::Location(const std::string& name, const std::string& description)
    : name(name), description(description) {}

// addCharacter(std::make_shared<Character>(charName, charDesc, 10)); // 10 points for interaction

// Get all characters in the location
std::vector<std::shared_ptr<Character>> Location::getAllCharacters() const {
    return characters;
}

// Get the name of the location
std::string Location::getName() {
    return name;
}

// Get the description of the location
std::string Location::getDescription() {
    return description;
}

// Describe the location, listing its exits, characters, items, and actions
void Location::describe() {
    std::cout << description << std::endl;
    listExits(); // List the exits

    if (!charactersLoaded) {
        loadCharactersFromFile("characters.txt"); // Load characters from file
        charactersLoaded = true; // Set the flag to true after loading
    }
    listCharacters(); // List the characters

    if (!itemsLoaded) {
        loadItemsFromFile("items.txt"); // Load items from file
        itemsLoaded = true; // Set the flag to true after loading
    }
    listItems(); // List the items

    if (!actionsLoaded) {
        loadActionsFromFile("Action.txt"); // Load items from file
        actionsLoaded = true; // Set the flag to true after loading
    }
    listActions(); // List the items
}

// Check if the location has any enemies
bool Location::hasEnemies() const {
    return !enemies.empty();
}

// Get all enemies in the location
std::vector<std::shared_ptr<Character>> Location::getEnemies() const {
    return enemies;
}


// Add an enemy to the location
void Location::addEnemy(std::shared_ptr<Character> enemy) {
    enemies.push_back(enemy);
}

// Set an exit for the location
void Location::setExit(const std::string& direction, std::shared_ptr<Location> location) {
    exits[direction] = location;
}

// Check if a direction has an exit
bool Location::hasExit(const std::string& direction) const {
    return exits.find(direction) != exits.end();
}

// Get all exits from the location
std::unordered_map<std::string, std::shared_ptr<Location>> Location::getExits() {
    return exits;
}


// Get the exit location for a specific direction
std::shared_ptr<Location> Location::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second;
    }
    return nullptr;
}

// Add a character to the location
void Location::addCharacter(const std::shared_ptr<Character> character) {
    characters.push_back(character);
}

// Add an item to the location
void Location::addItem(std::shared_ptr<Item> item) {
    items.push_back(item);
}

// Check if the location has a specific item
bool Location::hasItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return true;
        }
    }
    return false;
}

// Get the item by name
std::shared_ptr<Item> Location::getItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

// Remove an item from the location by name
std::shared_ptr<Item> Location::removeItem(const std::string& itemName) {
    auto it = std::find_if(items.begin(), items.end(), [&itemName](const std::shared_ptr<Item>& item) {
        return item->getName() == itemName;
    });
    
    if (it != items.end()) {
        std::shared_ptr<Item> item = *it;
        items.erase(it);
        return item;
    }
    return nullptr; // Return nullptr if the item was not found
}


// Remove a character from the location by name
void Location::removeCharacter(const std::string& characterName) {
    characters.erase(std::remove_if(characters.begin(), characters.end(),
        [&characterName](const std::shared_ptr<Character>& character) {
            return character->getName() == characterName;
        }), characters.end());
}

// List the exits from the location
void Location::listExits() const {
    if (exits.empty()) {
        std::cout << "There are no exits." << std::endl;
    } else {
        std::cout << "Exits: ";
        for (const auto& exit : exits) {
            std::cout << exit.first << " ";
        }
        std::cout << std::endl;
    }
}

// List the characters in the location
void Location::listCharacters() const {
    if (characters.empty()) {
        std::cout << "There are no other characters here." << std::endl;
    } else {
        std::cout << "Characters: " << std::endl;
        for (const auto& character : characters) {
            std::cout << character->getName() << ": " << character->getDescription() << std::endl; // Output name and description
        }
        std::cout << std::endl;
    }
}

// List the actions available in the location
void Location::listActions() const {
    for (const auto& action : actions) {
        std::cout << action->getName() << std::endl;
    }
}

// List the items in the location
void Location::listItems() const {
    if (items.empty()) {
        std::cout << "There are no other items here." << std::endl;
    } else {
        std::cout << "Items: " << std::endl;
        for (const auto& item : items) {
            std::cout << item->getName()  << ":" << item->getDescription() << std::endl; // Output name and description
        }
        std::cout << std::endl;
    }
}

// Load characters from a file
void Location::loadCharactersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening characters file: " << filename << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string locationName, charDetails;
        std::getline(stream, locationName, ':');
        if (locationName == name) {
            while (std::getline(stream, charDetails, ':')) {
                std::istringstream charStream(charDetails);
                std::string charName, charDesc, charType;
                int health = 100; // Default health
                int attackPower = 0; // Default attack power
                
                // Extract the character details
                std::getline(charStream, charName, ',');
                std::getline(charStream, charDesc, ',');
                std::getline(charStream, charType, ',');

                // Trim whitespace
                charName.erase(charName.find_last_not_of(" \n\r\t")+1);
                charDesc.erase(charDesc.find_last_not_of(" \n\r\t")+1);
                charType.erase(charType.find_last_not_of(" \n\r\t")+1);
                
                if (charType == "friendly") {
                    addCharacter(std::make_shared<Character>(charName, charDesc, true, health, attackPower));
                } else if (charType == "enemy") {
                    charStream >> health >> attackPower;
                    addCharacter(std::make_shared<Character>(charName, charDesc, false, health, attackPower));
                }
                std::cout << charName << " - " << charDesc << " for location: " << locationName << std::endl; // Debug statement
            }
        }
    }
}



// Load items from a file
void Location::loadItemsFromFile(const std::string& filename) {
    std::ifstream file(filename); // Open the file
    if (!file.is_open()) {
        std::cerr << "Error opening items file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) { // Read each line
        std::istringstream iss(line);
        std::string locName, itemName, itemDesc;
        if (std::getline(iss, locName, ':') && std::getline(iss, itemName, ':') && std::getline(iss, itemDesc)) {
            if (locName == name) { // Check if the location matches
                addItem(std::make_shared<Item>(itemName, itemDesc)); // Add the item
               //std::cout << itemName << " for Location: " << locName << std::endl;
            }
        }
    }
      //std::cout << std::endl; 
}

//Load actions from a file
void Location::loadActionsFromFile(const std::string& filename) {
    std::ifstream file(filename); // Open the file
    if (!file.is_open()) {
        std::cerr << "Error opening items file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) { // Read each line
        std::istringstream iss(line);
        std::string  actionName, actionDesc;
        if (std::getline(iss, actionName, ':') && std::getline(iss, actionDesc)) {
                addItem(std::make_shared<Item>(actionName, actionDesc)); // Add the item
              // std::cout << actionName << " : "  << actionDesc << std::endl;

        }
    }
}

//Add Enemy Characters 
void Location::addEnemyCharacter(const std::string& name, const std::string& description, bool friendly) {
    int health = 100;          // Example health
    int attackPower = 10;      // Example attack power
    auto enemy = std::make_shared<Character>(name, description, friendly, health, attackPower);
    enemies.push_back(enemy);
}

//handle Enenmy Activations 
void Location::activateEnemiesBasedOnItem(const std::string& itemName) {
    if (itemName == "Gold Jewelry") {
        addEnemyCharacter("Thief", "A sneaky thief", false);
    } else if (itemName == "Sword") {
        addEnemyCharacter("Goblin", "A fierce goblin", false);
    }
}

// Check if the location has a specific character
bool Location::hasCharacter(const std::string& characterName) {
    for (const auto& character : characters) {
        if (character->getName() == characterName) {
            return true;
        }
    }
    return false;
}

// Get the character by name
std::shared_ptr<Character> Location::getCharacter(const std::string& characterName) {
    for (const auto& character : characters) {
        if (character->getName() == characterName) {
            return character;
        }
    }
    return nullptr;
}
