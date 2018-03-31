//
//  yellowtang.cpp
//  Project2
//
//  Created by Nashir Janmohamed on 3/24/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include "yellowtang.h"
#include "fish.h"
#include <string>
#include <iostream>

//Implement Yellowtang’s constructor which must call its Fish constructor and then initializes any member variables.
Yellowtang::Yellowtang(int capacity, std::string name) : Fish(capacity, name){
    //initially, the fish hasn't seen anything, so it hasn't seen any bubbles
    bubbles = false;
}


//Copy constructor for a Yellowtang, calls Fish’s copy constructor to copy its Fish component and makes copies of any Yellowtang specific member variables.
Yellowtang::Yellowtang(const Yellowtang &other) : Fish(other){
    //copy Yellowtang member variables
    bubbles = other.bubbles;
}


//Implement Yellowtang’s overloaded assignment operator. Like all assignment operator overloads this should check to see if Yellowtang is being assigned to itself. Afterwards, like the copy constructor, should just call Fish’s overloaded assignment operator to assign its Fish. Then copy any Yellowtang specific member variables, then as always return itself.
Yellowtang& Yellowtang::operator=(const Yellowtang &other){
    if (this == &other)
        return (*this);
    
    //copy primitive fish data
    Fish::operator=(other);
    
    //copy Yellowtang member variables
    bubbles = other.bubbles;
    
    return (*this);
}


//Yellowtang remembers things exactly the way any other Fish does, but in addition keeps track if it has seen any bubbles, represented by the character ‘o’.
void Yellowtang::remember(char c){
    Fish::remember(c);
    
    //if any of the characters in fish's memory is an o, fish has seen bubbles, else it hasn't
    for (int i = 0; i < getCapacity(); i++){
        if (getMemory()[i] == 'o'){
            bubbles = true;
            return;
        }
    }
    bubbles = false;
}



//Yellowtang print’s its memory just like any other Fish, except if Yellowtang remembers any bubbles, in that case Yellowtang just prints “BUBBLES!”
void Yellowtang::printMemory() const{
    //if fish has seen bubbles, say BUBBLES! and don't print memory
    if (bubbles == true){
        std::cout << "BUBBLES!" << std::endl;
    }
    else
        Fish::printMemory();
}



//Yellowtang forgets just like Fish, but in addition to clearing its memory it also forgets that it has seen bubbles.
void Yellowtang::forget(){
    //reset to default state
    Fish::forget();
    bubbles = false;
}
