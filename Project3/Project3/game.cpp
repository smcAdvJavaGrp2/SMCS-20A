#include"game.h"
#include"aquarium.h"
#include"player.h"
#include"utils.h"
#include <cstdlib>
#include<iostream>
using namespace std;

Game::Game(std::string filename, int numSharks)
:m_maxSteps(0), m_automate(false){
    
    m_aquarium = new Aquarium(filename);
    
    // Arbitrarily set maximum number of sharks the half the number of open cells
    int maxSharks = m_aquarium->numOpenCells() / 2;
    if (numSharks > maxSharks) {
        std::cerr << "ERROR GAME: too many sharks: "<<numSharks
        <<" for game size: " << maxSharks << ". Exiting." << std::endl;
        exit(1);
    }
    
    for (int i = 0; i < numSharks; i++) {
        m_aquarium->addSharks();
    }
    
}

Game::~Game() {
    delete m_aquarium;
    m_aquarium = nullptr;
}

void Game::play(){
    // Game loop
    while (true) {
        m_aquarium->draw();
        
        if (m_aquarium->player()->stuck()) {
            cout << "Got stuck with no way out :( " << endl;
            cout << "Press enter to continue.";
            cin.ignore(10000, '\n');
            return;
        }
        
        if (m_aquarium->player()->getCurr() == m_aquarium->getEndPoint()) {
            cout << "You've reached the end! Congratulations! " << endl;
            cout << "Press enter to continue.";
            cin.ignore(10000, '\n');
            return;
        }
        
        if (!m_automate) {
            std::cout << "command (<space> to step, <a> to automate, <q> to quit): ";
            string action;
            getline(cin, action);
            switch (action[0]) {
                default:
                    cout << '\a' << endl;  // beep
                    continue;
                case 'q':
                    cout << "Quitting Game." << endl;
                    return;
                case ' ':
                    break;
                case 'a':
                    m_automate = true;
                    break;
            }
        }
        else {
            if (m_maxSteps >= MAX_STEPS) {
                cout << "Reached max steps, quitting." << endl;
                return;
            }
            delay(500);
        }
        m_maxSteps++;
        m_aquarium->update();
        m_aquarium->interact();
    }
}
