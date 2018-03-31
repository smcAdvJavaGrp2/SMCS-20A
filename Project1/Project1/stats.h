//
//  stats.h
//  Project1
//  Nashir Janmohamed
//

#ifndef stats_h
#define stats_h

///////////
/*
 When you press <s>, depending in how the current state evolved, you will see how many times a cell has been birthed, ‘.’ indicates no change, ‘A’ through ‘Z’ indicated the number of times it has been birthed (corresponding to 1 through 26, capping at 26).
 */
///////////

class Stats {
public:
    // Constructor/destructor
    Stats();
    ~Stats();
    
    // Accessors or Getters
    void display() const;
    
    // Mutators or Setters
    bool record(int r, int c, int val);
    
private:
    char **m_statsWorld;
};

#endif /* stats_h */
