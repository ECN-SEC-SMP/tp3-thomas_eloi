/**
 * @file forme.hpp
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

#include "point.hpp"

using namespace std;

template <typename T>
class Forme
{
protected:
    Point<T> centreForme_;

public:
    Forme(T x, T y) : centreForme_(x, y) {}
    Forme(Point<T> const &f) : centreForme_(f) {}
    ~Forme() = default;

    friend ostream &operator<<(ostream &s, Forme const &f)
    {
        s << " La forme à pour centre : " << f.centreForme_;
        return s;
    }

    virtual T perimetre();

    virtual T surface();
};