//
//  stats.cpp
//  Project1
//  Nashir Janmohamed
//

#include "stats.h"
#include "globals.h"
#include <iostream>

//The constructor initializes the Stats’s grid to correspond to the World’s, however Stats keeps tracks of a count of births for each cell, whereas the World simple displays the cells’ state, being represented by characters.
Stats::Stats(){
    m_statsWorld = new char*[MAX_ROWS];
    for (char i = 0; i < MAX_ROWS; i++) {
        m_statsWorld[i] = new char[MAX_COLS];
    }
    
    for (char i = 0; i < MAX_ROWS; i++) {
        for (char j = 0; j < MAX_COLS; j++) {
            m_statsWorld[i][j] = 0;
        }
    }
}

//The destructor cleans up the Stats object. Similar to how the World cleans up after itself.
Stats::~Stats(){
    for (char i = 0; i < MAX_ROWS; i++) {
        delete[] m_statsWorld[i];
    }
    delete[] m_statsWorld;
}

//The display member function prints the stats grid similar to what is seen in the example program.
// Accessors or Getters
void Stats::display() const{
    for (char i = 0; i < MAX_ROWS; i++) {
        for (char j = 0; j < MAX_COLS; j++) {
            if (m_statsWorld[i][j] == 0)
                std::cout << DEAD;
            else
                std::cout << (char)(m_statsWorld[i][j] + 64);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//The record function updates the Stats grid at row r and column c by increasing that cell by val. The record function should return false if the coordinates are out of bounds, and true otherwise.
// Mutators or Setters
bool Stats::record(int r, int c, int val) {
    if (r >= MAX_ROWS || r < 0 || c >= MAX_COLS || c < 0)
        return false;
    else {
        if ((m_statsWorld[r][c] + val) > 26)
            m_statsWorld[r][c] = 26;
        else if ((m_statsWorld[r][c] + val) < 0) //not sure how to handle negative val?
            m_statsWorld[r][c] = 0;
        else
            m_statsWorld[r][c] += val;
        return true;
    }
}
