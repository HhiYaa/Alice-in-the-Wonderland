#include "Inventory.h" 
#include <iostream> 
#include <algorithm> 
#include "Item.h" 

// Method to add an item to the inventory
void Inventory::addItem(const std::shared_ptr<Item>& item) {
    items.push_back(item); // Add the item to the items vector
}

// Method to remove an item from the inventory by name
std::shared_ptr<Item> Inventory::removeItem(const std::string& itemName) {
    // Find the item in the items vector by name
    auto it = std::find_if(items.begin(), items.end(),
                           [&itemName](const std::shared_ptr<Item>& item) {
                               return item->getName() == itemName;
                           });
    if (it != items.end()) {
        auto item = *it; // Get the item
        items.erase(it); // Remove the item from the vector
        return item; // Return the removed item
    }
    return nullptr; // Return nullptr if the item was not found
}

// Method to list all items in the inventory
void Inventory::listItems() const {
    if (items.empty()) {
        std::cout << "Your inventory is empty." << std::endl; // Print message if inventory is empty
        return;
    }
    std::cout << "Items in your inventory:" << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item->getName() << " " << item->getDescription() << std::endl; // List each item
    }
}

// Method to check if the inventory has an item by name
bool Inventory::hasItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item->getName() == itemName) { // Ensure Item class has a getName() method
            return true; // Return true if the item is found
        }
    }
    return false; // Return false if the item is not found
}

// Method to check if the inventory has a specific item
bool Inventory::hasItem(const std::shared_ptr<Item>& item) const {
    for (const auto& it : items) {
        if (it == item) {
            return true; // Return true if the item is found
        }
    }
    return false; // Return false if the item is not found
}

