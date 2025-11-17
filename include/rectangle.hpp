#pragma once
#include "forme.hpp"

template <typename T>
class Rectangle : public Forme<T> { 
    protected :
    T longueur_;
    T largeur_;    
    public :  
    Rectangle(Point<T> const &p1, T longueur, T largeur) : Forme<T>(p1), longueur_(longueur), largeur_(largeur) {}
    ~Rectangle() = default;
    T perimetre() override {
        return 2 * (longueur_ + largeur_);
    }
    T surface() override {
        return longueur_ * largeur_;
    }


};