#include"point.h"

Point::Point():m_x(0), m_y(0) {}

Point::Point(int x, int y): m_x(x), m_y(y) {}

int Point::getX() {
    return m_x;
}

int Point::getY() {
    return m_y;
}
void Point::set(int x, int y) {
    m_x = x;
    m_y = y;
}
bool Point::operator==(const Point& other) {
    return (m_x == other.m_x && m_y == other.m_y);
}

std::ostream & operator<<(std::ostream &os, const Point& p) {
    return os << "(" << p.m_x <<","<<p.m_y<<")";
}
