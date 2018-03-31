//
//  aquarium.h
//  Project2
//
//  Created by Nashir Janmohamed on 3/25/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#ifndef aquarium_h
#define aquarium_h

#include <iostream>
#include <string>
#include "fish.h"

const int MAX_FISH = 20;
class Aquarium {
public:
    Aquarium(); // Default Constructor
    bool addFish(Fish* fish); // Add Fish to Aquarium
    Fish *getFish(int n); // Get Fish at nth index
    void oracle(); // Read the Fish minds
    void feed(std::string food); // Put food into Aquarium
    void startle(); // Makes the Fish forget
private:
    Fish * m_fish[MAX_FISH]; // Pointers to Fish.
    int m_nFish; // Number of Fish.
};

#endif /* aquarium_h */
