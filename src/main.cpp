/**
 * @file main.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 17-11-2025
 *
 * @copyright Copyright (c) 2025
 *
 */


#include "point.hpp"
#include "forme.hpp"
#include "rectangle.hpp"
#include "carree.hpp"
#include "listeformes.hpp"

int main() {

    // Test de la classe Point int
     Point<int> p(2, 3);
        cout << p.getX() << endl;
        cout << p.getY() << endl;
        cout << p << endl;
        p.translater(1, -1);
        cout << p.getX() << endl;
        cout << p.getY() << endl;
        cout << p << endl;
        p.changeX(5);
        p.changeY(7);
        cout << p.getX() << endl;
        cout << p.getY() << endl;
        cout << p << endl;

    // Test de la classe Point float
    Point<float> pf(2.5, 3.5);
        cout << pf.getX() << endl;
        cout << pf.getY() << endl;
        cout << pf << endl;
        pf.translater(1.5, -1.5);
        cout << pf.getX() << endl;
        cout << pf.getY() << endl;
        cout << pf << endl;
        pf.changeX(5.5);
        pf.changeY(7.5);
        cout << pf.getX() << endl;
        cout << pf.getY() << endl;
        cout << pf << endl;

    // Specialization test for string
    Point<string> ps("2", "3");
        cout << ps.getX() << endl;
        cout << ps.getY() << endl;
        cout << ps << endl;
        ps.translater("4", "6");
        cout << ps.getX() << endl;
        cout << ps.getY() << endl;
        cout << ps << endl;

    // Test de la classe rectangle
    Rectangle<int> r(p, 4, 6);
        cout << r << endl;
        cout << "Périmètre : " << r.perimetre() << endl;
        cout << "Surface : " << r.surface() << endl;

    // Test de la classe carree
    Carree<int> c(p, 5);
        cout << c << endl;
        cout << "Périmètre : " << c.perimetre() << endl;
        cout << "Surface : " << c.surface() << endl;

    // Test de la classe listeformes
    ListeFormes<int> liste;
        liste.ajouterForme(new Rectangle<int>(Point<int>(0, 0), 4, 6));
        liste.ajouterForme(new Carree<int>(Point<int>(10, 10), 5));
        cout << "Nombre de formes : " << liste.nbFormes() << endl;
        cout << "Surface totale : " << liste.surfaceTotale() << endl;
        Rectangle<int> enveloppe = liste.enveloppeMinimale();
        cout << "Enveloppe minimale : " << enveloppe << endl;
    return 0;
}