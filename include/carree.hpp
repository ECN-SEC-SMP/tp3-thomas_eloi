/**
 * @file carree.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 17-11-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "rectangle.hpp"

/**
 * @brief Classe représentant un carré
 * 
 * @tparam T Type des coordonnées et dimensions
 */
template <typename T>
class Carree : public Rectangle<T> {
    protected :
    T cote_;

    public :
        Carree(Point<T> const &p1, T cote) : Rectangle<T>(p1, cote, cote), cote_(cote) {}
        ~Carree() = default;
        
};