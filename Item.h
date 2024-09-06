#ifndef ITEM_H
#define ITEM_H

#include <string> // Include the string library

class Item {
public:
    // Constructor to initialize Item with a name and description
    Item(const std::string& name, const std::string& description);
    
    // Get the name of the item
    std::string getName() const;
    
    // Get the description of the item
    std::string getDescription() const;
    
    // Get the points of the item
    int getPoints() const;
    
    // Add points to the player's score
    void addPoints(int points);

private:
    std::string name; // Name of the item
    std::string description; // Description of the item
    int points; // Points associated with the item
};

#endif // ITEM_H
