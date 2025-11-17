/**
 * @file rectangle.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 17-11-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "forme.hpp"

/**
 * @brief Classe représentant un rectangle
 * 
 * @tparam T Type des coordonnées et dimensions
 */
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
     template <typename U>
    friend ostream &operator<<(ostream &os, Rectangle<U> const &r);
};

// Définition de l’opérateur << (template à part)
template <typename U>
ostream &operator<<(ostream &os, Rectangle<U> const &r)
{
    os << "Rectangle : centre = " << r.centreForme_
       << ", longueur = " << r.longueur_
       << ", largeur = " << r.largeur_;
    return os;
}