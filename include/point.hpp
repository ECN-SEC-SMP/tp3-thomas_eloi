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
    void changeX(T x);
    void changeY(T y);

    friend ostream &operator<<(ostream& s, Point const &p);
};
