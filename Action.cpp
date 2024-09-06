#include "Action.h"
#include <iostream>
#include <functional>

// Constructor for the Action class, initializing name, actionFunc, and description
Action::Action(const std::string& name, std::function<void()> actionFunc, const std::string& description)
    :  name(name), actionFunc(actionFunc), description(description) {}

// Method to perform the action
void Action::perform() const {
    std::cout << description << std::endl;
    actionFunc();
}

// Method to get the name of the action
std::string Action::getName() const {
    return name;
}

// Method to get the description of the action
std::string Action::getDescription() const {
    return description;
}
