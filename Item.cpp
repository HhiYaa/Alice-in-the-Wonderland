#include "Item.h" 

// Constructor implementation for the Item class
Item::Item(const std::string& name, const std::string& description)
    : name(name), description(description) {}

// Get the name of the item
std::string Item::getName() const {
    return name;
}

// Get the description of the item
std::string Item::getDescription() const {
    return description;
}

// Get the points of the item
int Item::getPoints() const {
    return points;
}
