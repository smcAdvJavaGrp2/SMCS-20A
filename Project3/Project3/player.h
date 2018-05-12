#ifndef PLAYER_H
#define PLAYER_H
#include"actor.h"
#include"stack.h"
#include"list.h"

class Point;
class Aquarium;

class Player :public Actor {
public:
    Player(Aquarium* aquarium, Point p, std::string, char sprite);
    
    virtual void    update();    //
    virtual void    say();
    
    bool            stuck() const;
    
private:
    // Wrapper function to find if a point has been
    // placed inside the m_discovered List
    bool _discovered(Point p);
    
    // Stack to decide where to look next
    Stack<Point>    m_brain;
    
    // List to save all the visited areas,
    // Helps us decide where to look next
    List<Point>        m_discovered;
    
    // Stack to keep track of steps taken so
    // We can walk back towards the next place
    // to look.
    Stack<Point>    m_backTrack;
    
};

#endif//PLAYER_H
