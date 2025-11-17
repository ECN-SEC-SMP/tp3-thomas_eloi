/**
 * @file point.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 17-11-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <iostream>

using namespace std;

/**
 * @brief Classe représentant un point
 *
 * @tparam T Type des coordonnées
 */
template <typename T>
class Point
{
protected:
    T x_;
    T y_;

public:
    Point(T x, T y) : x_(x), y_(y) {}
    Point(Point const &p) : x_(p.x_), y_(p.y_) {}
    ~Point() = default;

    void translater(T dx, T dy)
    {
        this->x_ += dx;
        this->y_ += dy;
    }

    T getX() { return x_; }
    T getY() { return y_; }

    void changeX(T x) { x_ = x; }
    void changeY(T y) { y_ = y; }

    friend ostream &operator<<(ostream &s, Point const &p)
    {
        s << " le point à pour coordonnée x, y : (" << p.x_ << ", " << p.y_ << ")";
        return s;
    }
};
