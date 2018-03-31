//
//  yellowtang.h
//  Project2
//
//  Created by Nashir Janmohamed on 3/24/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#ifndef yellowtang_h
#define yellowtang_h

#include <iostream>
#include <string>
#include "fish.h"


//Yellowtang is just like any other fish except in the presence of bubbles Yellowtang gets excited and can’t remember anything other than BUBBLES!

class Yellowtang : public Fish {
public:
    Yellowtang(int capacity, std::string name); // Constructor
    Yellowtang(const Yellowtang &other); // Copy Constructor
    Yellowtang &operator=(const Yellowtang &other); // Assignment Operator
    // Overridden functions
    virtual void remember(char c);
    virtual void printMemory() const;
    virtual void forget();
private:
    // TODO: declare any private member variables/functions here
    bool bubbles;
};

#endif /* yellowtang_h */
