
# TP3 - Template

- SEC 2
- Eloi Tourangin - eloi.tourangin@eleves.ec-nantes.fr
- Thomas Verron - thomas.verron@eleves.ec-nantes.fr

## Table des matières

1. [Objectif du TP](#objectif-du-tp)
2. [Compilation et Exécution](#compilation-et-exécution)
3. [Architecture du Projet](#architecture-du-projet)
4. [Implémentation Détaillée](#implémentation-détaillée)
5. [Résultats des Tests](#résultats-des-tests)
6. [Diagrammes de Classes](#diagrammes-de-classes)

---

## Compilation et Exécution

### Méthode 1 : Utiliser make
```bash
# Compiler
make

# Exécuter
./build/main.out
```

### Méthode 2 : Utiliser le script bash
```bash
./build_and_execute.sh
```

---

## Architecture du Projet

### Structure des fichiers

```
include/
├── point.hpp           # Classe template Point
├── forme.hpp           # Classe abstraite template Forme
├── rectangle.hpp       # Classe Rectangle héritant de Forme
├── carree.hpp          # Classe Carree héritant de Rectangle
└── listeformes.hpp     # Classe ListeFormes pour gérer une collection de formes

src/
└── main.cpp            # Programme principal avec jeux de tests
```

---

## Implémentation Détaillée

### 1. Classe Point (point.hpp)

#### Description
La classe `Point<T>` est une classe template représentant un point dans un plan 2D avec des coordonnées de type générique.

#### Attributs
- `T x_` : abscisse du point
- `T y_` : ordonnée du point

#### Méthodes

| Méthode | Description |
|---------|-------------|
| `Point(T x, T y)` | Constructeur paramétralisé |
| `Point(Point const &p)` | Constructeur de recopie |
| `void translater(T dx, T dy)` | Translate le point |
| `T getX()`, `T getY()` | Accesseurs |
| `void changeX(T x)`, `void changeY(T y)` | Mutateurs |
| `friend ostream &operator<<(...)` | Affichage du point |

#### Spécialisation
Une **spécialisation totale** du template a été implémentée pour le type `string` :
```cpp
template <>
void Point<string>::translater(string dx, string dy)   
{
    swap(x_, dx);
    swap(y_, dy);
}
```
Cette spécialisation utilise `swap()` pour échanger les valeurs de chaînes de caractères au lieu de les additionner.

#### Jeux de Tests
```
Entrée : Point<int> p(2, 3)
Sortie :  le point à pour coordonnée x, y : (2, 3)

Entrée : p.translater(1, -1) 
Sortie :  le point à pour coordonnée x, y : (3, 2)

Entrée : Point<float> pf(2.5, 3.5) puis translater(1.5, -1.5)
Sortie :  le point à pour coordonnée x, y : (4, 2)

Entrée : Point<string> ps("2", "3") puis translater("4", "6")
Sortie :  le point à pour coordonnée x, y : (4, 6)
```

---

### 2. Classe Forme (forme.hpp)

#### Description
`Forme<T>` est une classe abstraite template représentant une forme géométrique générique centrée sur un point.

#### Attributs
- `Point<T> centreForme_` : le centre de la forme

#### Méthodes

| Méthode | Description |
|---------|-------------|
| `Forme(T x, T y)` | Constructeur avec coordonnées |
| `Forme(Point<T> const &f)` | Constructeur avec Point |
| `virtual T perimetre() = 0` | Méthode abstraite pour le périmètre |
| `virtual T surface() = 0` | Méthode abstraite pour la surface |
| `friend ostream &operator<<(...)` | Affichage du centre |

#### Remarques
- Les méthodes abstraites `perimetre()` et `surface()` retournent un type générique (par défaut `T`) mais peuvent potentiellement être spécialisées pour éviter les pertes de précision lors d'opérations sur entiers.
- L'opérateur `<<` est implémenté sous forme de fonction amie.

---

### 3. Classe Rectangle (rectangle.hpp)

#### Description
`Rectangle<T>` est une classe concrète héritant de `Forme<T>` représentant un rectangle aligné sur les axes.

#### Attributs hérités
- `Point<T> centreForme_` (de Forme)

#### Attributs propres
- `T longueur_` : longueur du rectangle
- `T largeur_` : largeur du rectangle

#### Méthodes

| Méthode | Description |
|---------|-------------|
| `Rectangle(Point<T> const &p1, T longueur, T largeur)` | Constructeur |
| `T perimetre() override` | Retourne 2×(longueur + largeur) |
| `T surface() override` | Retourne longueur × largeur |
| `template <typename U> friend ostream &operator<<(...)` | Affichage détaillé |

#### Jeux de Tests
```
Entrée : Rectangle<int> r(p, 4, 6)  où p = (3, 2)
Sortie : Rectangle : centre =  le point à pour coordonnée x, y : (3, 2), longueur = 4, largeur = 6
Périmètre : 20
Surface : 24
```

---

### 4. Classe Carree (carree.hpp)

#### Description
`Carree<T>` est une classe concrète héritant de `Rectangle<T>` représentant un carré (cas spécial du rectangle).

#### Attributs hérités
- De Forme : `Point<T> centreForme_`
- De Rectangle : `T longueur_`, `T largeur_`

#### Attributs propres
- `T cote_` : côté du carré

#### Constructeur
```cpp
Carree(Point<T> const &p1, T cote) : Rectangle<T>(p1, cote, cote), cote_(cote)
```
Le carré initialise le rectangle avec longueur = largeur = cote.

#### Jeux de Tests
```
Entrée : Carree<int> c(p, 5)  où p = (3, 2)
Sortie : Carré : centre =  le point à pour coordonnée x, y : (3, 2), côtés = 5
Périmètre : 20
Surface : 25
```

---

### 5. Classe ListeFormes (listeformes.hpp)

#### Description
`ListeFormes<T>` gère une collection de pointeurs vers des `Forme<T>` et offre des opérations sur l'ensemble.

#### Attributs
- `std::vector<Forme<T> *> formes_` : conteneur des formes

#### Méthodes

| Méthode | Description |
|---------|-------------|
| `ListeFormes()` | Constructeur par défaut |
| `~ListeFormes()` | Destructeur (désallocation mémoire) |
| `void ajouterForme(Forme<T> *f)` | Ajoute une forme à la liste |
| `void supprimerForme(int index)` | Supprime une forme et libère la mémoire |
| `int nbFormes() const` | Retourne le nombre de formes |
| `T surfaceTotale() const` | Calcule la somme des surfaces |
| `Rectangle<T> enveloppeMinimale() const` | Calcule la boîte englobante |

#### Détails de l'enveloppe minimale
La méthode `enveloppeMinimale()` :
1. Récupère les coordonnées de tous les centres des formes
2. Détermine les limites min/max en x et y
3. Construit un rectangle englobant avec :
   - Centre : point médian de la boîte
   - Longueur : maxX - minX
   - Largeur : maxY - minY

#### Remarques
- Gestion automatique de la mémoire via le destructeur
- Utilisation de `vector<>` pour la flexibilité
- Polymorphisme : peut contenir tout type de Forme (Rectangle, Carree, etc.)

---

## Résultats des Tests

### Exécution du programme principal

```
Test Classe Point<int>
======================
Affichage initial : le point à pour coordonnée x, y : (2, 3)
Après translater(1, -1) : le point à pour coordonnée x, y : (3, 2)
Après modifications : le point à pour coordonnée x, y : (5, 7)

Test Classe Point<float>
========================
Affichage initial : le point à pour coordonnée x, y : (2.5, 3.5)
Après translater(1.5, -1.5) : le point à pour coordonnée x, y : (4, 2)
Après modifications : le point à pour coordonnée x, y : (5.5, 7.5)

Test Spécialisation Point<string>
==================================
Affichage initial : le point à pour coordonnée x, y : (2, 3)
Après translater("4", "6") avec swap : le point à pour coordonnée x, y : (4, 6)

Test Classe Rectangle<int>
===========================
Rectangle : centre =  le point à pour coordonnée x, y : (5, 7), longueur = 4, largeur = 6
Périmètre : 20
Surface : 24

Test Classe Carree<int>
=======================
Carré : centre =  le point à pour coordonnée x, y : (5, 7), côtés = 5
Périmètre : 20
Surface : 25
```

---

## Diagrammes de Classes

### Hiérarchie d'héritage

```
Point<T>
  ▲
  │
  │ (contient)
  │
Forme<T> (classe abstraite)
  ▲
  │
  ├─ Rectangle<T>
  │    ▲
  │    │
  │    └─ Carree<T>
  │
  └─ [Autres formes possibles]

ListeFormes<T>
  │
  └─ vector<Forme<T>*>
```

### Relations entre classes

| Classe | Type de Relation | Classe liée | Description |
|--------|------------------|-------------|------------|
| `Point<T>` | - | - | Classe indépendante |
| `Forme<T>` | Contient | `Point<T>` | Le centre est un Point |
| `Rectangle<T>` | Hérite de | `Forme<T>` | Implémentation concrète |
| `Carree<T>` | Hérite de | `Rectangle<T>` | Cas spécial du rectangle |
| `ListeFormes<T>` | Contient | `Forme<T>*` | Gère une collection polymorphe |

---