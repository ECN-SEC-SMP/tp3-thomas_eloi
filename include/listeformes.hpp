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
    ListeFormes() = default;
    ~ListeFormes()
    {
        for (auto f : formes_)
        {
            delete f;
        }
    }

    void ajouterForme(Forme<T> *f)
    {
        formes_.push_back(f);
    }

    void supprimerForme(int index) {
        if (index >= 0 && index < formes_.size()) {
            delete formes_[index];
            formes_.erase(formes_.begin() + index);
        }
    }

    int nbFormes() const
    {
        return formes_.size();
    }

    T surfaceTotale() const
    {
        T total = 0;
        for (auto f : formes_)
        {
            total += f->surface();
        }
        return total;
    }

    Rectangle<T> enveloppeMinimale() const
    {
        if (formes_.empty())
        {
            throw std::runtime_error("La liste de formes est vide.");
        }

        T minX = formes_[0]->centreForme_.getX();
        T maxX = formes_[0]->centreForme_.getX();
        T minY = formes_[0]->centreForme_.getY();
        T maxY = formes_[0]->centreForme_.getY();

        for (auto f : formes_)
        {
            T x = f->centreForme_.getX();
            T y = f->centreForme_.getY();

            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }

        Point<T> centre((minX + maxX) / 2, (minY + maxY) / 2);
        T longueur = maxX - minX;
        T largeur = maxY - minY;

        return Rectangle<T>(centre, longueur, largeur);
    }
};