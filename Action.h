// #ifndef ACTION_H
// #define ACTION_H

// #include <string>
// #include <functional>

// // Action class: Represents actions that can be performed in the game
// class Action {
// public:
//     Action(const std::string& name, const std::string& description, std::function<void()> actionFunc);  // Constructor
//     std::string getName() const;  // Get action name
//     std::string getDescription() const;  // Get action description

// private:
//     std::string name;  // Action name
//     std::string description;  // Action description
// };

// #endif // ACTION_H


#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <functional>

class Action {
public:
    Action(const std::string& name, std::function<void()> actionFunc, const std::string& description);   // Constructor for the Action class
    std::string getName() const;    // Method to get the name of the action
    std::string getDescription() const;   // Method to get the description of the action
    void perform() const; // Method to perform the action

private:
    std::string description; // Description of the action
    std::string name; // Name of the action
    std::function<void()> actionFunc; // Function to execute the action
};

#endif
