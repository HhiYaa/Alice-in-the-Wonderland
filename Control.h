#ifndef CONTROL_H
#define CONTROL_H

#include "Location.h" // Include the Location header file
#include "Character.h" // Include the Character header file
#include "Item.h" // Include the Item header file
#include "Inventory.h" // Include the Inventory header file
#include <string> // Include the string library
#include <memory> // Include the memory library for std::shared_ptr
#include <map> // Include the map container
#include <vector> // Include the vector container
#include <unordered_set> // Include the unordered_set container

// Control class: Manages game flow and processes user commands
class Control {
public:
    // Constructor for the Control class
    Control();

    // Method to run the game
    void run();
    
    // Method to add points
    void addPoints(int points);
    
    // Method to initialize the game
    void initializeGame();
    
    // Method to display the game guide
    void displayGameGuide();
    
    // Method to process a command
    bool processCommand(const std::string& command);
    
    // Method to handle fighting a character
    void fightCharacter(const std::string& characterName);
    
    // Method to handle fleeing from a character
    void fleeFromCharacter(const std::string& characterName);
    
    // Method to exit lists
    void ExitLists() const;
    
    // Method to use an item
    void useItem(const std::string& itemName, bool inCombat, int* enemyHealth);
    
    // Boolean to check if the player has played chess with the queen
    bool hasPlayedChessWithQueen;
    
    // Method to play chess with the queen
    bool playChessWithQueen();
    
    // Method to handle enemy interaction
    void handleEnemyInteraction(const std::shared_ptr<Character>& enemy);
    
    // Method to interact with a character
    void interactCharacter(const std::string& characterName);
    
    // Method to handle item pickup
    void handleItemPickup(const std::string& itemName);
    
    // Method to take an item
    void take(const std::string& itemName);
    
    // Method to interact in the courtroom
    void interactInCourtroom();
    
    // Method to interact with the queen
    void interactWithQueen();

private:
    std::map<std::string, std::shared_ptr<Location>> locations; // Map of location names to Location objects
    // std::map<std::string, std::shared_ptr<Location>> Character; // Commented out character map
    std::shared_ptr<Location> currentLocation; // Pointer to the current location
    std::shared_ptr<Inventory> inventory; // Pointer to the player's inventory
    std::vector<std::shared_ptr<Character>> characters; // Vector of characters
    std::unordered_set<std::string> visitedLocations; // Set of visited locations
    std::map<std::string, std::string> itemDesc; // Map of item names to descriptions
    std::shared_ptr<Character> player; // Pointer to the player character
    
    // Helper method to trim whitespace from a string
    std::string trim(const std::string& str);
    
    // Helper method to convert a string to lowercase
    std::string toLower(const std::string& str);
    
    // Method to get the next location
    std::shared_ptr<Location> getNextLocation();
    
    int points; // Points in the game
    int health; // Health of the player
 
};

#endif // CONTROL_H
