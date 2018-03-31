//
//  aquarium.cpp
//  Project2
//
//  Created by Nashir Janmohamed on 3/25/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
#include <string>
#include "aquarium.h"
#include "fish.h"

//Initially there are no Fish in the Aquarium.
Aquarium::Aquarium(){
    m_nFish = 0;
}


//Implement addFish, which takes a pointer to Fish. If the Fish cannot be added because the Aquarium already has MAX_FISH-many Fish residing, return false and don’t add any. Otherwise, return true.
bool Aquarium::addFish(Fish* fish){
    if (m_nFish == MAX_FISH)
        return false;
    //else
    m_fish[m_nFish] = fish;
    m_nFish++;
    return true;
}


//Implement getFish, which returns the pointer to the nth Fish that is added. Return nullptr if there is less than n Fish in the Aquarium, or if n is an invalid position.
Fish* Aquarium::getFish(int n){
    if (m_nFish < n || n < 0) //n >= MAX_FISH is redundant in this case
        return nullptr;
    else
        return m_fish[n];
}


//Oracle reads the Fishies’ minds; It prints the memory of all Fish in the Aquarium along with indicating which Fish had those thoughts.
void Aquarium::oracle(){
    for (int i = 0; i < m_nFish; i++)
    {
        std::cout << m_fish[i]->getName() << " ";
        m_fish[i]->printMemory();
    }
}


//Feed the Fish by providing a string of characters, each Fish in turn will encounter a character and remember that character, once encountered no other Fish can encounter that character. For example, suppose you have two Fish and if you feed the Fish “abc”, the first Fish will encounter the ‘a’, the second Fish will encounter the ‘b’, finally the first Fish will encounter the ‘c’.
void Aquarium::feed(std::string food){
    //METHOD 1
    for (size_t len = food.length(), i = 0, current_fish = 0; len > 0; len--, i++, current_fish++){
        if (current_fish == m_nFish)
            current_fish = 0;
        m_fish[current_fish]->remember(food[i]);
    }
    //METHOD 2
//    int i = 0, current_fish = 0, len = (int)food.length();
//    while (len > 0){
//        if (current_fish == m_nFish)
//            current_fish = 0;
//        m_fish[current_fish]->remember(food[i]);
//        //increment loop variables
//        i++; current_fish++; len--;
//    }
}


//Startle will cause all the Fish to forget.
void Aquarium::startle(){
    for (int i = 0; i < m_nFish; i++)
    {
        m_fish[i]->forget();
    }
}
