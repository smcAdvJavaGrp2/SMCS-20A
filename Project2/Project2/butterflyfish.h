//
//  butterflyfish.h
//  Project2
//
//  Created by Nashir Janmohamed on 3/24/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#ifndef butterflyfish_h
#define butterflyfish_h

#include <iostream>
#include <string>
#include "fish.h"

//Butterflyfish is another type of Fish, except has an extended memory in addition to Fish’s memory. Not only does it store characters in its limited capacity memory, it also has memory that can expand once it reaches its capacity. Not only that, it remembers how many times it has seen any character. Similar to Fish’s memory, the number of unique characters Butterflyfish as seen is not necessarily its capacity. Butterflyfish’s definition is provided below:

class Butterflyfish : public Fish {
public:
    Butterflyfish(int capacity, std::string name); // Constructor
    Butterflyfish(const Butterflyfish &other); // Copy Constructor
    Butterflyfish &operator=(const Butterflyfish &other); // Assignment Operator
    virtual ~Butterflyfish(); // Destructor
    // Overridden Functions
    virtual void remember(char c);
    virtual void printMemory() const;
private:
    // TODO: declare any private member variables/functions here
    char** resizeMemory(char** original, int size, int capacity);
    int m_extended, m_size;
    char **m_unique;
};

#endif /* butterflyfish_h */
