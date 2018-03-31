//
//  fish.h
//  Project2
//
//  Created by Nashir Janmohamed on 3/20/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#ifndef fish_h
#define fish_h

#include <iostream>
#include <string>


//This models a creature that is intelligent enough to remember some capacity of characters at a time. But, a Fish might not use up its entire capacity, it might just remember some amount that is less than its capacity. For example a Fish might be able to remember 10 characters, but may only have encountered 2 so far.

class Fish {
public:
    Fish(int capacity, std::string name);// Constructor
    Fish(const Fish &other); // Copy Constructor
    virtual ~Fish(); // Destructor
    Fish &operator=(const Fish &other); // Assignment Operator
    virtual void remember(char c); // Remember c
    virtual void forget(); // Clears memory by filling in '.'
    virtual void printMemory() const;// Prints memory
    std::string getName();
protected:
    const char* getMemory() const;// Returns memory
    int getAmount() const; // Returns amount remembered
    int getCapacity() const; // Returns memory capacity
private:
    // TODO: declare any private member variables/functions here
    int m_capacity, m_remembered; //memory capacity, number of characters remembered
    std::string m_name;
    char* m_mem;
};

#endif /* fish_h */
