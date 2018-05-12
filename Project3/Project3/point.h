#ifndef POINT_H
#define POINT_H
#include<ostream>

// Points on 2d grid
class Point {
    // Overloaded output stream "(x,y)"
    friend std::ostream & operator<<(std::ostream &os, const Point& p);
    
public:
    Point();
    Point(int x, int y);
    
    // Will make use of implicit copy constructor and assignment operators
    // for shallow copy, which is fine since there is no dynamically
    // allocated memory.
    
    int getX();
    int getY();
    void set(int x, int y);
    
    // overloaded assignment operator, two points are equal
    // if both their elements are equal
    bool operator==(const Point &other);
private:
    int m_x, m_y;
};

#endif//POINT_H
