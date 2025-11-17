/**
 * @file listeforme.hpp
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
#include <vector>

using namespace std;

/**
 * @brief Classe représentant une liste de formes
 *
 * @tparam T Type des coordonnées
 */
template <typename T>
class ListeFormes
{
protected:
    std::vector<Forme<T> *> formes_;

public:
}