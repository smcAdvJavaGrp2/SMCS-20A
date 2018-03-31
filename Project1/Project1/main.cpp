//
//  main.cpp
//  Project 1
//  Nashir Janmohamed
//

#include <iostream>
#include "life.h"
#include "glider.h"
#include "blinker.h"
#include "game.h"

int main() {
    Life **population = new Life*[2];

    //population[0] = new Blinker(4, 5); //blinker alone
    //int numLife = 1;

    //population[0] = new Glider(0,0); //glider alone
    //int numLife = 1;

    population[0] = new Glider(0, 0); // Blinker and Glider
    population[1] = new Blinker(4, 5);
    int numLife = 2;

    // Create the game
    Game g(population, numLife);

    // Run the game
    g.play();

    // Clean up
    delete population[0];
    delete population[1];
    delete[] population;    
}
