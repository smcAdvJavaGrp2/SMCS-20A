//
//  butterflyfish.cpp
//  Project2
//
//  Created by Nashir Janmohamed on 3/24/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include "fish.h"
#include "butterflyfish.h"
#include <string>
#include <iostream>


//Implement Butterflyfish’s constructor which must call its Fish constructor and then initializes its own member variables. Butterflyfish’s dynamically allocated extended memory starts of the same size as Fish’s. Recall that Butterflyfish’s extended memory keeps track of two things: any unique characters encountered and the number of times it has seen them. It starts off not having seen anything.
Butterflyfish::Butterflyfish(int capacity, std::string name) : Fish(capacity, name){
    //initialize member varialbes
    m_extended = capacity;
    m_size = 0;
    //2 dimensional array, column 1 is char, column 2 is number of occurences for a given character
    m_unique = new char*[m_extended];
    for (int i = 0; i < m_extended; i++){
        m_unique[i] = new char[2];
        m_unique[i][0] = '.';
        m_unique[i][1] = 0;
    }
}



//Copy constructor for a Butterflyfish, calls Fish’s copy constructor to copy its Fish component and makes copies of any Butterflyfish specific member variables. Pay special mind to any dynamically allocated member variables.
Butterflyfish::Butterflyfish(const Butterflyfish &other) : Fish(other){
    m_extended = other.m_extended;
    m_size = other.m_size;
    m_unique = new char*[m_extended];
    for (int i = 0; i < m_extended; i++){
        m_unique[i] = new char[2];
        for (int j = 0; j < 2; j++)
            m_unique[i][j] = other.m_unique[i][j];
    }
}



//Implement Butterflyfish overloaded assignment operator. Like all assignment operator overloads this should check to see if Butterflyfish is being assigned to itself. Afterwards, like the copy constructor, should just call Fish’s overloaded assignment operator to assign its Fish. Then copy any Butterflyfish specific member variables, like the copy constructor pay special mind to any dynamically allocated member variables, then as always return itself.
Butterflyfish& Butterflyfish::operator=(const Butterflyfish &other){
    if (this == &other)
        return (*this);
    
    //copy primitive fish data
    Fish::operator=(other);
    
    //delete existing memory
    for (int i = 0; i < m_extended; i++){
        delete [] m_unique[i];
    }
    delete [] m_unique;
    
    //copy Butterflyfish member variables
    m_extended = other.m_extended;
    m_size = other.m_size;
    
    //allocate new memory
    m_unique = new char*[m_extended];
    for (int i = 0; i < m_extended; i++){
        m_unique[i] = new char[2];
        for (int j = 0; j < 2; j++)
            //copy all values from "other"
            m_unique[i][j] = other.m_unique[i][j];
    }
    return (*this);
}


// Destructor
Butterflyfish::~Butterflyfish(){
    for (int i = 0; i < m_extended; i++){
        delete [] m_unique[i];
    }
    delete [] m_unique;
}


//Butterflyfish remembers things exactly the way any other Fish does, but in addition keeps track of unique characters and a count of each time it has seen those characters. If its extended memory fills up to its capacity, Butterflyfish expands its character and counter memory by doubling its capacity.
void Butterflyfish::Butterflyfish::remember(char c){
    //update parent object
    Fish::remember(c);
    if (m_size == m_extended){
        m_extended *= 2;
        m_unique = resizeMemory(m_unique, m_size, m_extended);
    }
    
    //check if passed in character has been seen already, and if so increment the count for that char
    for (int i = 0; i < m_size; i++){
        if (m_unique[i][0] == c)
        {
            m_unique[i][1]++;
            return;
        }
    }
    //record the new char and set m_unique[m_size] to 1
    m_unique[m_size][0] = c;
    m_unique[m_size][1]++;
    m_size++;
}


//Butterflyfish print’s its memory just like any other Fish, but in addition to that it says “I’m Obnoxious!”, then prints out each of the unique characters it has seen along with the number of times it has seen them.
void Butterflyfish::printMemory() const{
    Fish::printMemory();
    std::cout << "I'm Obnoxious!" << std::endl;
    if (m_size != 0)
        std::cout << "I've seen:" << std::endl;
    for (int i = 0; i < m_size; i++){
        if (m_unique[i][1] != 0){
            std::cout << "  " << m_unique[i][0] << " " << (int)m_unique[i][1] << " times!" << std::endl;
        }
    }
}

char** Butterflyfish::resizeMemory(char** original, int size, int capacity){
    //create new array "temp"
    char **temp = new char*[capacity];
    for (int i = 0; i < capacity; i++){
        temp[i] = new char[2];
        temp[i][0] = '.';
        temp[i][1] = 0;
    }
    //copy existing values to temp
    for (int i = 0; i < size; i++)
        for (int j = 0; j < 2; j++)
            temp[i][j] = original[i][j];
    //delete existing array "m_unique"
    for (int i = 0; i < (capacity/2); i++){
        delete [] original[i];
    }
    delete [] original;
    
    //point m_unique to newly created array
    return temp;
}
