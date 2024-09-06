#ifndef CHARACTER_H
#define CHARACTER_H

#include <string> 
#include "Inventory.h" 
#include "Location.h" 

class Character {
public:
    // Constructor for the Character class
    Character(const std::string& name, const std::string& description, bool friendly, int health, int attackPower);
    
    // Method to get the name of the character
    std::string getName() const;
    
    // Method to get the description of the character
    std::string getDescription() const;
    
    // Method to check if the character is friendly
    bool isFriendly() const;
    
    // Method to get the health of the character
    int getHealth() const;
    
    // Method to get the attack power of the character
    int getAttackPower() const;
    
    // Method to reduce the health of the character
    void reduceHealth(int amount);
    
    // Method to interact with the character
    int interact();
    
    // Method to attack another character
    void attack(Character& target);
    
    // Method to check if the character is an enemy
    bool isEnemy() const;

private:
    std::string name; // Name of the character
    std::string description; // Description of the character
    bool friendly; // Indicates if the character is friendly
    int points; // Points associated with the character
    int health; // Health of the character
    int attackPower; // Attack power of the character
};

#endif
