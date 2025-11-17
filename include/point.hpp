#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Point {
protected:
    T x_;
    T y_;
public:
    Point(T x, T y);
    Point(Point const& p);
    void translater(T dx, t dy);
    T getX();
    T getY();
    void changeX(T x) : x_(x) {}
    void changeY(T y) : y_(y) {}

    friend ostream &operator<<(ostream& s, Point const &p) {
        s << " le point à pour coordonnée x, y : (" << p.x_ << ", " << p.y_ << ")";
        return s;
    }
};
