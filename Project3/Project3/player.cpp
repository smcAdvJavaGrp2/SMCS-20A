#include"player.h"
#include"actor.h"
#include"stack.h"
#include"list.h"
#include"point.h"
#include"aquarium.h"

#include<iostream>

// 1. Player( ... )
//        Constructs and initializes the Player/Actor and its member variables
//        Remembers and discovers the starting point.
Player::Player(Aquarium* aquarium, Point p, std::string name, char sprite)
:Actor(aquarium, p, name, sprite), m_brain(), m_discovered(){
    // Discover the starting point
    m_discovered.addToFront(p);
    m_brain.push(p);
}

// 2. stuck()
bool Player::stuck() const {
    return getState() == State::STUCK;
}

// 3. update()
//        This function implements an algorithm to look through the maze
//        for places to move (STATE::LOOKING). update also handles moving the
//        player as well, if there is an open undiscovered cell to move to the
//        player just moves there.  However, there will be cases in which there
//        are no open or undiscovered cells, at this point the player must
//        backtrack (State::BACKTRACK) to a point that is adjacent to the next
//        point the player was planning to visit
//
//        Backtracking is challenging, save it for the very very very last thing.
//        Make sure the Looking aspect compiles and works first.
void Player::update() {
    //POP the top point off of the stack.
    Point p;
    if (getState() == State::BACKTRACK){
        p = m_backTrack.peek();
        m_backTrack.pop();
    }
    else{ // (getState() == State::LOOKING)
        p = m_brain.peek();
        m_brain.pop();
    }
    //don't need to handle STUCK or FREEDOM here as they both happen at the end of Player::update()
    
    setCurr(p);
    m_backTrack.push(p);
    
    //looking algorithm
    if (getState() == State::LOOKING){
        //If slot to the WEST is open & is undiscovered
        Point w(p.getX()-1, p.getY());
        if(!_discovered(w) && getAquarium()->isCellOpen(w)){
            m_brain.push(w); //PUSH (curx-1,cury) on stack.
            m_discovered.addToFront(w);
        }
        //If slot to the EAST is open & is undiscovered
        Point e(p.getX()+1, p.getY());
        if(!_discovered(e) && getAquarium()->isCellOpen(e)){
            m_brain.push(e); //PUSH (curx+1,cury) on stack.
            m_discovered.addToFront(e);
        }
        //If slot to the NORTH is open & is undiscovered
        Point n(p.getX(), p.getY()+1);
        if(!_discovered(n) && getAquarium()->isCellOpen(n)){
            m_brain.push(n); //PUSH (curx,cury+1) on stack.
            m_discovered.addToFront(n);
        }
        //If slot to the SOUTH is open & is undiscovered
        Point s(p.getX(), p.getY()-1);
        if(!_discovered(s) && getAquarium()->isCellOpen(s)){
            m_brain.push(s); //PUSH (curx,cury-1) on stack.
            m_discovered.addToFront(s);
        }
        //If we’re at the endpoint, DONE!
        if (p == getAquarium()->getEndPoint()){
            setState(State::FREEDOM);
            return;
        }
    }
    
    //BACKTRACKING
    Point comp;
    if (!m_brain.isEmpty())
        comp = m_brain.peek();
    else
        comp = m_backTrack.peek();
    int px = p.getX();
    int py = p.getY();
    int compx = comp.getX();
    int compy = comp.getY();
    if ((px == compx + 1 && py == compy) || (px == compx - 1 && py == compy) || (px == compx && py == compy + 1) || (px == compx && py == compy - 1))
        setState(State::LOOKING);
    else{
        m_backTrack.pop();
        setState(State::BACKTRACK);
    }
    
    if (m_brain.isEmpty())
        setState(State::STUCK);
}

// 4. say()
//        Already Implemented, nothing to do here
void Player::say() {
    
    // Freedom supercedes being eaten
    if (getState() == State::FREEDOM) {
        std::cout << getName() << ": WEEEEEEEEEEEEEEE!";
        return;
    }
    
    // Being eaten supercedes being lost
    switch (getInteract()) {
        case Interact::ATTACK:
            std::cout << getName() << ": OUCH!";
            break;
        case Interact::GREET:
            break;
        case Interact::ALONE:
        default:
            switch (getState()) {
                case State::LOOKING:
                    std::cout << getName() << ": Where's the exit?";
                    break;
                case State::STUCK:
                    std::cout << getName() << ": Oh no! I'm Trapped!";
                    break;
                case State::BACKTRACK:
                    std::cout << getName() << ": Argh, all walls or discovered, gotta backtrack...";
                    break;
                default:
                    break;
            }
            
            break;
    }
}

// _discovered
//        returns true if the item is in the list
bool Player::_discovered(Point p) {
    return (m_discovered.findItem(p) != -1);
}
