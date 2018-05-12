#ifndef GAME_H
#define GAME_H
#include<string>

class Aquarium;

const int MAX_STEPS = 100;

class Game {
public:
    // Dynamically allocates an aquarium and adds sharks
    Game(std::string filename, int numSharks);
    ~Game();
    
    void play();
private:
    Aquarium*    m_aquarium;
    bool        m_automate;
    int            m_maxSteps;
    
};

#endif//GAME_H
