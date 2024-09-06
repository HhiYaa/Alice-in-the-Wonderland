// // Location.h
#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <unordered_map>
#include "Character.h"
#include "Action.h"

// Forward declaration of Character class
class Character;
class Item;

class Location {
public:
    Location(const std::string& name, const std::string& description); // Constructor to initialize Location with a name and description
    std::string getName() ; // Get the name of the location
    std::string getDescription() ; // Get the description of the location
    void describe(); // Describe the location
    void setExit(const std::string& direction, std::shared_ptr<Location> location); // Set an exit for the location
    bool hasExit(const std::string& direction) const; // Check if a direction has an exit
    std::unordered_map<std::string, std::shared_ptr<Location>> getExits();
    std::shared_ptr<Location> getExit(const std::string& direction) const;

    
    bool hasCharacter(const std::string& characterName);
    void addCharacter(const std::shared_ptr<Character> character); // Add a character to the location
    std::shared_ptr<Character> getCharacter(const std::string& characterName);

    void addItem(std::shared_ptr<Item> item); // Add an item to the location
    bool hasItem(const std::string& itemName) const;
    //void removeItem(std::shared_ptr<Item> item);
    // std::shared_ptr<Item> takeItem(const std::string& itemName);
    std::shared_ptr<Item> removeItem(const std::string& itemName);
    //std::shared_ptr<Location> getExit(const std::string& direction); // Get the exit location for a direction
    // Get the item by name
    std::shared_ptr<Item> getItem(const std::string& itemName) const;

    void listExits() const; // List the exits from the location
    void listCharacters() const; // List the characters in the location
    void listItems() const; // List the items in the location
    void listActions() const; // List the items in the location

    void loadCharactersFromFile(const std::string& filename); // Load characters from a file
    void loadItemsFromFile(const std::string& filename); // Load items from a file
     void loadActionsFromFile(const std::string& filename); // Load actions from a file
    void activateEnemiesBasedOnItem(const std::string& itemName);
    void addEnemyCharacter(const std::string& name, const std::string& description, bool friendly);
    //addCharacter(std::make_shared<Character>(charName, charDesc, 10)); // 10 points for interaction

    bool hasEnemies() const;
    std::vector<std::shared_ptr<Character>> getEnemies() const;
    void addEnemy(std::shared_ptr<Character> enemy);
    void removeCharacter(const std::string& characterName);
    void outputAllData() const;
    std::vector<std::shared_ptr<Character>> getAllCharacters() const;

private:
    std::string name; // Name of the location
    std::string description; // Description of the location
//    std::unordered_map<std::string, std::shared_ptr<Location>> exit;

  std::unordered_map<std::string, std::shared_ptr<Location>> exits;
   // std::map<std::string, std::shared_ptr<Location>> exits; // Exits from the location
    std::vector<std::shared_ptr<Character>> characters; // Characters in the location
    std::vector<std::shared_ptr<Item>> items; // Items in the location
    std::vector<std::shared_ptr<Action>> actions; // Items in the location
    std::unordered_map<std::string, std::vector<std::shared_ptr<Character>>> itemActivatedEnemies;
    std::vector<std::shared_ptr<Character>> enemies;
    std::vector<std::shared_ptr<Item>> erase(const std::string&);
    //std::vector<std::shared_ptr<Character>> characters;

    bool charactersLoaded; // Flag to check if characters are loaded
    bool itemsLoaded; // Flag to check if items are loaded
    bool actionsLoaded;
    std::map<std::string, std::string> itemDescriptions;
    // void populateItemEnemyMappings(); 
     //void checkForEnemies();

};

#endif // LOCATION_H



///



//WORKED WITHOUT LOAD TXT FILESSSSS
// #ifndef LOCATION_H
// #define LOCATION_H

// #include <string>
// #include <unordered_map>
// #include <vector>
// #include <memory>
// #include "Character.h"
// #include "Item.h"
// #include "Action.h"

// class Enemy; // Forward declaration
// class Character; // Forward declaration

// class Enemy; // Forward declaration

// class Location {
// public:
//     Location(const std::string& name, const std::string& description); // Constructor to initialize Location with a name and description
//    std::string getName() const; // Get the name of the location
//    std::string getDescription() const; // Get the description of the location
//     void describe() const; // Describe the location

//    void listExits() const;
//     void listItems() const; // New method
//     void listCharacters() const; // New method

//     void setExit(const std::string& direction, std::shared_ptr<Location> location); // Set an exit for the location
//     bool hasExit(const std::string& direction) const; // Check if a direction has an exit
//     std::shared_ptr<Location> getExit(const std::string& direction) const; // Get the exit location for a direction

//      void addCharacter(std::shared_ptr<Character.txt> character); // Add a character to the location
//     void addItem(std::shared_ptr<Item.txt> item); // Add an item to the location
//     void loadCharactersFromFile(const std::string& Character.txt); // Load characters from a file
//     void loadItemsFromFile(const std::string& Item.txt); // Load items from a file

    
//     void addAction(std::shared_ptr<Action> action);
//     void addEnemy(std::shared_ptr<Enemy> enemy);

//     // bool interact(const std::string& characterName);
//     // bool interact(const std::string& characterName, int &points);
//     // std::shared_ptr<Enemy> getEnemy(const std::string& enemyName);

// private:
//     std::string name; // Name of the location
//     std::string description; // Description of the location
//     std::unordered_map<std::string, std::shared_ptr<Location>> exits; // Exits from the location
//     std::vector<std::shared_ptr<Character>> characters; // Characters in the location
//     std::vector<std::shared_ptr<Item>> items; // Items in the location
//     std::vector<std::shared_ptr<Action>> actions;
//     std::vector<std::shared_ptr<Enemy>> enemies;

//     // void listExits() const;
//     // void listItems() const; // New method
//     // void listCharacters() const; // New method
    
// };

// #endif



//break


   // void listItems() const; // New method
    // void listCharacters() const; // New method


//Location thingy error
// #ifndef LOCATION_H
// #define LOCATION_H

// #include <string>
// #include <unordered_map>
// #include <vector>
// #include <memory>
// #include "Character.h"


// class Character; 

// class Location {
// public:
//      std::shared_ptr<Character> getEnemy() const;
//     Location(const std::string& name, const std::string& description);
//     std::string getName() const;
//     std::string getDescription() const;
//     void setExit(const std::string& direction, std::shared_ptr<Location> location);
//     bool hasExit(const std::string& direction) const;
//     std::shared_ptr<Location> getExit(const std::string& direction) const;
//     void addCharacter(std::shared_ptr<Character> character);
//     void describe() const;
//     void listExits();

// private:
//     std::string name;
//     std::string description;
//     std::unordered_map<std::string, std::shared_ptr<Location>> exits;
//     std::vector<std::shared_ptr<Character>> characters;
// };

// #endif // LOCATION_H



// #ifndef LOCATION_H
// #define LOCATION_H

// #include <string>
// #include <unordered_map>
// #include <vector>
// #include <memory>
// #include "Character.h"
// #include "Item.h"
// #include "Action.h"

// class Enemy; // Forward declaration

// class Location {
// public:
//     Location(const std::string& name, const std::string& description);
//     const std::string& getName() const;
//     const std::string& getDescription() const;
//     void describe() const;
//     void listExits();
//     void setExit(const std::string& direction, std::shared_ptr<Location> location);
//     bool hasExit(const std::string& direction) const;
//     std::shared_ptr<Location> getExit(const std::string& direction) const;
//   //  void addCharacter(std::shared_ptr<Character> character);
//     void addItem(std::shared_ptr<Item> item);
//     void addAction(std::shared_ptr<Action> action);
//     //bool interact(const std::string& characterName);
//     void addEnemy(std::shared_ptr<Enemy> enemy);
//     //bool interact(const std::string& characterName, int &points);
//     std::shared_ptr<Enemy> getEnemy(const std::string& enemyName);

// private:
//     std::string name;
//     std::string description;
//    std::unordered_map<std::string, std::shared_ptr<Location>> exits;
//     //std::map<std::string, std::shared_ptr<Location>> exits;
//  //  std::vector<std::shared_ptr<Character>> characters;
//     std::vector<std::shared_ptr<Item>> items;
//     std::vector<std::shared_ptr<Action>> actions;
//     std::vector<std::shared_ptr<Enemy>> enemies;
// };



// #endif


// #ifndef LOCATION_H
// #define LOCATION_H

// #include <string>
// #include <vector>
// #include <map>
// #include <memory>
// #include "Character.h"
// #include "Action.h"

// class Location {
// public:
//     Location(const std::string& name, const std::string& description);

//     void addCharacter(const std::shared_ptr<Character>& character);
//     void addAction(const std::shared_ptr<Action>& action);
//     void describe() const;
//     void performActions() const;
//     bool interact(const std::string& characterName);

//     void setExit(const std::string& direction, std::shared_ptr<Location> location);
//     bool hasExit(const std::string& direction) const;
//     std::shared_ptr<Location> getExit(const std::string& direction) const;

//     std::string getName() const;
//     std::string getDescription() const;

//     const std::vector<std::shared_ptr<Character>>& getCharacters() const;

// private:
//     std::string name;
//     std::string description;
//     std::vector<std::shared_ptr<Character>> characters;
//     std::vector<std::shared_ptr<Action>> actions;
//     std::map<std::string, std::shared_ptr<Location>> exits;
// };

// #endif // LOCATION_H


// #ifndef LOCATION_H
// #define LOCATION_H

// #include <memory>
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include "Character.h"
// #include "Action.h"

// class Location {
// public:
//     Location(const std::string& name, const std::string& description);

//     void addCharacter(const std::shared_ptr<Character>& character);
//     void addAction(const std::shared_ptr<Action>& action);
//     void describe() const;
//     void performActions() const;
//     bool interact(const std::string& characterName);
//     void setExit(const std::string& direction, std::shared_ptr<Location> location);
//     bool hasExit(const std::string& direction) const;
//     std::shared_ptr<Location> getExit(const std::string& direction) const;

// private:
//     std::string name;
//     std::string description;
//     std::vector<std::shared_ptr<Character>> characters;
//     std::vector<std::shared_ptr<Action>> actions;
//     std::unordered_map<std::string, std::shared_ptr<Location>> exits;
// };

// #endif // LOCATION_H

// #ifndef LOCATION_H
// #define LOCATION_H

// #include <string>
// #include <memory>
// #include <unordered_map> // Include unordered_map header for std::unordered_map

// class Character;
// class Action;

// class Location {
// public:
//     Location(const std::string& name, const std::string& description);

//     void addCharacter(const std::shared_ptr<Character>& character);
//     void addAction(const std::shared_ptr<Action>& action);
//     void describe() const;
//     void performActions() const;
//     bool interact(const std::string& characterName);

//     // Directional exits
//     void setExit(const std::string& direction, std::shared_ptr<Location> location);
//     bool hasExit(const std::string& direction) const;
//     std::shared_ptr<Location> getExit(const std::string& direction) const;

// private:
//     std::string name;
//     std::string description;
//     std::unordered_map<std::string, std::shared_ptr<Character>> charactersMap; // Use unordered_map for characters
//     std::unordered_map<std::string, std::shared_ptr<Action>> actionsMap; // Use unordered_map for actions
//     std::unordered_map<std::string, std::shared_ptr<Location>> exits; // Use unordered_map for exits
// };

// #endif // LOCATION_H

// #ifndef LOCATION_H
// #define LOCATION_H

// #include <string>
// #include <memory>
// #include <map> // Include map header for std::map

// class Location {
// public:
//     Location(const std::string& name, const std::string& description);

//     void addCharacter(const std::shared_ptr<Character>& character);
//     void addAction(const std::shared_ptr<Action>& action);
//     void describe() const;
//     void performActions() const;
//     bool interact(const std::string& characterName);

//     // Directional exits
//     void setExit(const std::string& direction, std::shared_ptr<Location> location);
//     bool hasExit(const std::string& direction) const;
//     std::shared_ptr<Location> getExit(const std::string& direction) const;

// private:
//     std::string name;
//     std::string description;
//     std::vector<std::shared_ptr<Character>> characters;
//     std::vector<std::shared_ptr<Action>> actions;
//     std::map<std::string, std::shared_ptr<Location>> exits; // Map for exits
// };

// #endif // LOCATION_H

// #ifndef LOCATION_H
// #define LOCATION_H

// #include "Character.h"
// #include "Action.h"
// #include <vector>
// #include <string>
// #include <memory>

// class Location {
// public:
//     Location(const std::string& name, const std::string& description);

//     void addCharacter(const std::shared_ptr<Character>& character);
//     void addAction(const std::shared_ptr<Action>& action);

//     void describe() const;
//     void performActions() const;
//     bool interact(const std::string& characterName); // Added declaration

//     void setExit(const std::string& direction, std::shared_ptr<Location> location);
//     bool hasExit(const std::string& direction) const;
//     std::shared_ptr<Location> getExit(const std::string& direction) const;

// private:
//     std::string name;
//     std::string description;
//     std::vector<std::shared_ptr<Character>> characters;
//     std::vector<std::shared_ptr<Action>> actions;
//     std::map<std::string, std::shared_ptr<Location>> exits;
// };

// #endif
