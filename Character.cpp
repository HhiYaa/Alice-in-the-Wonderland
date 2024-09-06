#include "Character.h"
#include <iostream>

// Constructor for the Character class, initializing name, description, friendly, health, and attackPower
Character::Character(const std::string& name, const std::string& description, bool friendly, int health, int attackPower)
    : name(name), description(description), friendly(friendly), health(health), attackPower(attackPower) {}

// Method to get the name of the character
std::string Character::getName() const {
    return name;
}

// Method to get the description of the character
std::string Character::getDescription() const {
    return description;
}

// Method to interact with the character, returns points
int Character::interact() {
    std::cout << "Interacting with " << name << std::endl;
    return points; // Return the points for interacting with this character
}

// Method to check if the character is friendly
bool Character::isFriendly() const {
    return friendly;
}

// Method to check if the character is an enemy
bool Character::isEnemy() const {
    return !friendly;
}


// Method to get the health of the character
int Character::getHealth() const {
    return health;
}

// Method to get the attack power of the character
int Character::getAttackPower() const {
    return attackPower;
}

// Method to reduce the health of the character
void Character::reduceHealth(int amount) {
    health -= amount;
     if (health < 0) {
        health = 0;
    }
}

// Method to attack another character
void Character::attack(Character& target) {
    target.reduceHealth(attackPower);
    std::cout << name << " attacks " << target.getName() << " for " << attackPower << " damage!" << std::endl;
}

