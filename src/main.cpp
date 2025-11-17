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

    // Test de la classe rectangle
    Rectangle<int> r(p, 4, 6);
        cout << r << endl;
        cout << "Périmètre : " << r.perimetre() << endl;
        cout << "Surface : " << r.surface() << endl;

    return 0;
}