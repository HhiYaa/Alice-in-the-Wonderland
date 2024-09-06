#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector> // Include the vector container
#include <memory> // Include the memory library for std::shared_ptr
#include "Item.h" // Include the Item header file

class Item; // Forward declaration of the Item class

class Inventory {
public:
    // Method to add an item to the inventory
    void addItem(const std::shared_ptr<Item>& item);
    
    // Method to list all items in the inventory
    void listItems() const;
    
    // Method to remove an item from the inventory by name
    std::shared_ptr<Item> removeItem(const std::string& itemName);
    
    // Method to check if the inventory has an item by name
    bool hasItem(const std::string& itemName) const;
    
    // Method to check if the inventory has a specific item
    bool hasItem(const std::shared_ptr<Item>& item) const;

private:
    std::vector<std::shared_ptr<Item>> items; // Vector of items in the inventory
};

#endif // INVENTORY_H

