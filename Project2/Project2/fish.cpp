//
//  fish.cpp
//  Project2
//
//  Created by Nashir Janmohamed on 3/20/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include "fish.h"
#include <string>
#include <iostream>

//Dynamically allocate capacity-many characters for the Fish’s memory. Initialize its memory with dot('.')s. If capacity is not positive, then set it to 3 by default. Since, this is a brand new fish it uses none of its capacity. Also, save the Fish’s name.
Fish::Fish(int capacity, std::string name){
    if (capacity < 1)
        m_capacity = 3;
    else
        m_capacity = capacity;
    m_remembered = 0;
    m_name = name;
    m_mem = new char[m_capacity];
    for (int i = 0; i < m_capacity; i++){
        m_mem[i] = '.';
    }
}

//Copy constructor for a Fish, when declaring a new Fish we can make it an exact copy of another.
Fish::Fish(const Fish &other){
    m_capacity = other.m_capacity;
    m_remembered = other.m_remembered;
    m_name = other.m_name;
    m_mem = new char[m_capacity];
    for (int i = 0; i < m_capacity; i++){
        m_mem[i] = other.m_mem[i];
    }
}

//Clean up dynamically allocated memory.
Fish::~Fish(){
    delete [] m_mem;
}


//Overloaded assignment operator so we can assign one declared fish to be an exact copy of another declared fish.
Fish& Fish::operator=(const Fish &other){
    if (&other == this)
        return *this;
    //delete existing memory
    delete [] m_mem;
    
    //copy member variables
    m_capacity = other.m_capacity;
    m_remembered = other.m_remembered;
    m_name = other.m_name;
    
    //copy dynamically allocated memory and set all values equal to that of the values of "other"
    m_mem = new char[m_capacity];
    for (int i = 0; i < m_capacity; i++){
        m_mem[i] = other.m_mem[i];
    }
    
    return (*this);
}


//Implement remember. Store the character c into the Fish’s memory. If you already have the max capacity characters memorized, then discard the oldest character in memory to open up a free slot. (This is an example of LRU (Least Recently Used) replacement.). Update the amount of characters remembered appropriately.
void Fish::remember(char c){
    //if at max capacity, forget the oldest character and shift each character backwards one spot
    //i.e. memory = acgk, a is oldest, after b is inputted, memory = cgkb
    if (m_remembered == m_capacity){
        for (int i = 0; i < m_capacity-1; i++){
            m_mem[i] = m_mem[i+1];
        }
        m_mem[m_remembered-1] = c;
    }
    else{
        m_mem[m_remembered] = c;
        m_remembered++;
    }
}

//Implement forget, clear memory by filling dot('.')s into memory. This implies that there are no characters remembered.
void Fish::forget(){
    //set all values to periods
    for (int i = 0; i < m_capacity; i++){
        m_mem[i] = '.';
    }
    
    m_remembered = 0;
}



//Print to console what is in Fish’s memory.
void Fish::printMemory() const{
    for (int i = 0; i < m_capacity; i++){
        std::cout << m_mem[i];
    }
    std::cout << std::endl;
}


//Gets the Fish’s name.
std::string Fish::getName(){
    return m_name;
}

//Gets the Fish’s memory.
const char* Fish::getMemory() const{
    return m_mem;
}

//Gets the amount of characters remembered.
int Fish::getAmount() const{
    return m_remembered;
}


//Gets the Fish’s capacity.
int Fish::getCapacity() const{
    return m_capacity;
}
