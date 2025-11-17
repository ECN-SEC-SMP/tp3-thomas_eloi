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


using namespace std;

int main() {

    // Test de la classe Point

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

    return 0;
}