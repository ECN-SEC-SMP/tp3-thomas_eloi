
# TP2 - Hiérarchie de classes et héritage multiple

- SEC 2
- Eloi Tourangin - eloi.tourangin@eleves.ec-nantes.fr
- Thomas Verron - thomas.verron@eleves.ec-nantes.fr

Ce projet implémente une hiérarchie de classes pour modéliser différents types de véhicules, illustrant les concepts d'héritage simple et multiple en C++.

## Classes implémentées

- `Vehicule` : Classe de base représentant un véhicule générique avec les attributs et méthodes communs.
- `Voiture` : Classe dérivée de Vehicule représentant une voiture (maximum 5 places).
- `Bateau` : Classe dérivée de Vehicule représentant un bateau (vitesse maximale de 300 km/h).
- `VoitureAmphibie` : Classe utilisant l'héritage multiple de Voiture et Bateau, possédant deux ensembles d'attributs distincts.

## Table des matières

- [Compilation et éxecution](#compilation-et-éxecution)
- [Classe Vehicule](#classe-vehicule)
- [Classe Voiture](#classe-voiture)
- [Classe Bateau](#classe-bateau)
- [Classe VoitureAmphibie](#classe-voitureamphibie)

<div style="page-break-after: always;"></div>

# Compilation et éxecution

```bash
# Compiler
make

# Exécuter
./build/main.out
```

ou executer le script bash

```bash
./build_and_execute.sh
```

# Classe Vehicule

La classe `Vehicule` est une classe abstraite qui sert de base pour différents types de véhicules. Elle contient des attributs et des méthodes communes à tous les véhicules.

## Attributs

- `vitesse_` : Vitesse actuelle du véhicule.
- `vitesseMax_`' : Vitesse maximale du véhicule.
- `nbPlaces_` : Nombre maximum de places dans le véhicule.
- `occupants_` : Nombre actuel d'occupants dans le véhicule.
- `etat_` : État du véhicule (0 : ARRET, 1 : MARCHE, 2 : PANNE_LEGERE, 3 : PANNE_SEVERE).

## Méthodes

- `Vehicule(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0)` : Constructeur de la classe.
- `demarrer()` : Démarre le véhicule.
- `arreter()` : Arrête le véhicule.
- `depanner()` : Dépanne le véhicule.
- `accelerer(int increment)` : Accélère le véhicule d'un certain incrément.
- `freiner(int decrement)` : Freine le véhicule d'un certain décrément.
- `monter(int nbOcc)` : Fait monter un certain nombre d'occupants
- `descendre(int nbOcc)` : Fait descendre un certain nombre d'occupants.
- `mettreEnPanne(double random)` : Met le véhicule en panne selon une probabilité
- `getEtat() const` : Retourne l'état actuel du véhicule sous forme de chaîne de caractères.
- `~Vehicule()` : Destructeur de la classe.
- `operator<<` : Surcharge de l'opérateur d'insertion pour afficher les informations du véhicule.

### Constructeur Vehicule

```cpp
Vehicule(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0)
```

Initialise un véhicule avec une vitesse maximale, un nombre de places et un nombre d'occupants initial. Le véhicule est créé à l'état ARRET avec une vitesse nulle.

**Contraintes :**
- Le nombre de places doit être ≥ 1
- Le nombre d'occupants ne peut pas dépasser le nombre de places

**Tests (`testVehiculeConstruct`) :**
- Création avec 0 places → Exception `invalid_argument`
- Création avec plus d'occupants que de places (6 occupants pour 5 places) → Exception `invalid_argument`
- Création valide (120 km/h max, 5 places, 2 occupants) → Succès

### Méthode demarrer

```cpp
virtual void demarrer()
```

Démarre le véhicule en changeant son état de ARRET à MARCHE.

**Contraintes :**
- Le véhicule ne doit pas être déjà en marche
- Le véhicule ne doit pas être en panne

**Tests (`testVehiculeDemarrer`) :**
- Démarrage normal → Succès
- Tentative de redémarrage alors qu'il est déjà en marche → Exception `runtime_error`
- Tentative de démarrage d'un véhicule en panne → Exception `runtime_error`

### Méthode arreter

```cpp
virtual void arreter()
```

Arrête le véhicule en changeant son état de MARCHE à ARRET.

**Contraintes :**
- La vitesse doit être à 0 km/h
- Le véhicule ne doit pas être déjà à l'arrêt

**Tests (`testVehiculeArreter`) :**
- Tentative d'arrêt avec vitesse non nulle (50 km/h) → Exception `runtime_error`
- Arrêt après freinage complet → Succès
- Tentative d'arrêt alors qu'il est déjà arrêté → Exception `runtime_error`

### Méthode depanner

```cpp
virtual void depanner()
```

Répare le véhicule en le remettant à l'état ARRET s'il était en panne (légère ou sévère).

**Contraintes :**
- Le véhicule doit être en panne (PANNE_LEGERE ou PANNE_SEVERE)

**Tests (`testVehiculeDepanner`) :**
- Tentative de dépanner un véhicule non en panne (à l'arrêt) → Exception `runtime_error`
- Tentative de dépanner un véhicule en marche → Exception `runtime_error`
- Dépannage d'un véhicule en panne légère → Succès

### Méthode accelerer

```cpp
virtual void accelerer(int increment)
```

Augmente ou diminue la vitesse du véhicule d'une valeur donnée (increment peut être négatif).

**Contraintes :**
- Le véhicule doit être en marche
- La nouvelle vitesse ne doit pas être négative
- La nouvelle vitesse ne doit pas dépasser la vitesse maximale

**Tests (`testVehiculeAccelerer`) :**
- Tentative d'accélération à l'arrêt → Exception `runtime_error`
- Tentative d'accélération avec valeur négative résultant en vitesse < 0 → Exception `invalid_argument`
- Tentative d'accélération dépassant la vitesse max (150 km/h alors que max = 120) → Exception `invalid_argument`
- Accélération normale de 50 km/h → Succès

### Méthode freiner

```cpp
virtual void freiner(int decrement)
```

Diminue la vitesse du véhicule. Le décrement doit être une valeur positive.

**Contraintes :**
- Le véhicule doit être en marche
- Le décrement doit être positif
- La vitesse résultante ne doit pas être négative

**Tests (`testVehiculeFreiner`) :**
- Tentative de freinage à l'arrêt → Exception `runtime_error`
- Tentative de freinage avec valeur négative → Exception `invalid_argument`
- Freinage normal de 20 km/h → Succès
- Freinage excessif (50 km/h alors que vitesse = 30 km/h) → Exception `invalid_argument`

### Méthode monter

```cpp
virtual void monter(int nbOcc)
```

Fait monter un nombre donné d'occupants dans le véhicule.

**Contraintes :**
- Le véhicule doit être à l'arrêt
- Le nombre d'occupants à faire monter doit être positif
- Le nombre total d'occupants ne doit pas dépasser le nombre de places

**Tests (`testVehiculeMonter`) :**
- Tentative de faire monter -1 personne → Exception `invalid_argument`
- Tentative de faire monter 6 personnes dans un véhicule de 5 places → Exception `invalid_argument`
- Tentative de faire monter des personnes pendant que le véhicule roule → Exception `runtime_error`
- Faire monter 3 personnes normalement → Succès

### Méthode descendre

```cpp
virtual void descendre(int nbOcc)
```

Fait descendre un nombre donné d'occupants du véhicule.

**Contraintes :**
- Le véhicule doit être à l'arrêt
- Le nombre d'occupants à faire descendre doit être positif
- Le nombre d'occupants à faire descendre ne doit pas dépasser le nombre actuel d'occupants

**Tests (`testVehiculeDescendre`) :**
- Tentative de faire descendre -1 personne → Exception `invalid_argument`
- Tentative de faire descendre 1 personne alors qu'il n'y a personne → Exception `invalid_argument`
- Tentative de faire descendre 5 personnes alors qu'il n'y en a que 3 → Exception `invalid_argument`
- Tentative de faire descendre des personnes pendant que le véhicule roule → Exception `runtime_error`
- Faire descendre 2 personnes normalement → Succès

### Méthode mettreEnPanne

```cpp
virtual void mettreEnPanne(double random)
```

Met le véhicule en panne. La sévérité de la panne dépend de la valeur aléatoire fournie.
- Si random < 0.5 : Panne légère (PANNE_LEGERE)
- Si random ≥ 0.5 : Panne sévère (PANNE_SEVERE)

**Contraintes :**
- Le véhicule ne doit pas être déjà en panne

**Tests (`testVehiculeMettreEnPanne`) :**
- Mise en panne légère (random = 0.3) → Succès
- Tentative de mettre en panne un véhicule déjà en panne → Exception `runtime_error`

### Méthode getEtat

```cpp
virtual string getEtat() const
```

Retourne l'état actuel du véhicule sous forme de chaîne de caractères.

**Valeurs possibles :**
- "Arrêt" pour ARRET
- "Marche" pour MARCHE
- "Panne légère" pour PANNE_LEGERE
- "Panne sévère" pour PANNE_SEVERE

Cette méthode est utilisée dans l'affichage des attributs et ne lève pas d'exception.

### Destructeur ~Vehicule

```cpp
virtual ~Vehicule()
```

Détruit le véhicule en réinitialisant tous ses attributs à 0 et affiche un message de confirmation.

### Surcharge de l'opérateur <<

```cpp
ostream &operator<<(ostream &s, Vehicule const &v)
```

Permet d'afficher la fiche technique complète d'un véhicule avec tous ses attributs (vitesse, vitesse max, places, occupants, état).

---

# Classe Voiture

La classe `Voiture` hérite de `Vehicule` et ajoute une contrainte spécifique : une voiture ne peut pas avoir plus de 5 places.

## Attributs

Hérite de tous les attributs de `Vehicule`.

## Méthodes

### Constructeur Voiture

```cpp
Voiture(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0)
```

Appelle le constructeur de `Vehicule` et vérifie la contrainte spécifique aux voitures.

**Contrainte supplémentaire :**
- Le nombre de places doit être ≤ 5

**Tests (`testVoitureConstruct`) :**
- Création d'une voiture 6 places → Exception `invalid_argument`
- Création avec plus d'occupants que de places → Exception `invalid_argument`
- Création valide (120 km/h max, 5 places, 4 occupants) → Succès

### Méthode demarrer

```cpp
virtual void demarrer()
```

Redéfinition de la méthode `demarrer()` avec des messages spécifiques à la voiture ("La voiture à démarré").

**Tests (`testVoitureDemarrer`) :**
- Démarrage normal → Succès avec message spécifique
- Tentative de redémarrage → Exception `runtime_error`
- Démarrage d'une voiture en panne → Exception `runtime_error`

### Méthode arreter

```cpp
virtual void arreter()
```

Redéfinition de la méthode `arreter()` avec des messages spécifiques à la voiture ("La voiture s'est arrêté").

**Tests (`testVoitureArreter`) :**
- Tentative d'arrêt à 50 km/h → Exception `runtime_error`
- Arrêt après freinage complet → Succès
- Tentative d'arrêt déjà à l'arrêt → Exception `runtime_error`

### Destructeur ~Voiture

```cpp
virtual ~Voiture()
```

Destructeur de la voiture (commenté dans le code pour éviter trop de messages).

---

# Classe Bateau

La classe `Bateau` hérite de `Vehicule` et ajoute une contrainte spécifique : un bateau ne peut pas dépasser 300 km/h.

## Attributs

Hérite de tous les attributs de `Vehicule`.

## Méthodes

### Constructeur Bateau

```cpp
Bateau(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0)
```

Appelle le constructeur de `Vehicule` et vérifie la contrainte spécifique aux bateaux.

**Contrainte supplémentaire :**
- La vitesse maximale doit être ≤ 300 km/h

**Tests (`testBateauConstruct`) :**
- Création d'un bateau trop rapide (350 km/h) → Exception `invalid_argument`
- Création avec plus d'occupants que de places → Exception `invalid_argument`
- Création valide (120 km/h max, 5 places, 4 occupants) → Succès

### Méthode demarrer

```cpp
virtual void demarrer()
```

Redéfinition de la méthode `demarrer()` avec des messages spécifiques au bateau ("Le bateau à démarré").

**Tests (`testBateauDemarrer`) :**
- Démarrage normal → Succès avec message spécifique
- Tentative de redémarrage → Exception `runtime_error`
- Démarrage d'un bateau en panne → Exception `runtime_error`

### Méthode arreter

```cpp
virtual void arreter()
```

Redéfinition de la méthode `arreter()` avec des messages spécifiques au bateau ("Le bateau s'est arrêté").

**Tests (`testBateauArreter`) :**
- Tentative d'arrêt à 50 km/h → Exception `runtime_error`
- Arrêt après freinage complet → Succès
- Tentative d'arrêt déjà à l'arrêt → Exception `runtime_error`

### Destructeur ~Bateau

```cpp
virtual ~Bateau()
```

Destructeur du bateau (commenté dans le code pour éviter trop de messages).

---

# Classe VoitureAmphibie

La classe `VoitureAmphibie` utilise l'**héritage multiple** en héritant simultanément de `Voiture` et `Bateau`. Cette classe illustre le problème du diamant : elle possède **deux instances distinctes** des attributs de `Vehicule` (une via `Voiture`, une via `Bateau`).

## Caractéristiques principales

- **Héritage multiple** : `class VoitureAmphibie : public Voiture, public Bateau`
- **Double attributs** : Possède deux ensembles complets d'attributs (vitesse, vitesseMax, nbPlaces, occupants, etat)
- **Vitesses maximales différentes** : Peut avoir une vitesse max différente sur route et sur eau
- **Modes indépendants** : Les modes voiture et bateau peuvent être dans des états différents

## Attributs

Hérite de tous les attributs de `Voiture` ET de `Bateau`, créant ainsi deux ensembles d'attributs provenant de `Vehicule`.

## Méthodes

### Constructeur VoitureAmphibie

```cpp
VoitureAmphibie(int vitesseMaxVoiture = 0, int vitesseMaxBateau = 0, int nbPlaces = 1, int occupants = 0)
```

Initialise les deux classes de base avec des vitesses maximales potentiellement différentes.

**Contraintes cumulées :**
- Contrainte de `Voiture` : nbPlaces ≤ 5
- Contrainte de `Bateau` : vitesseMaxBateau ≤ 300 km/h
- Contrainte de `Vehicule` (héritée deux fois) : occupants ≤ nbPlaces

**Tests (`testVoitureAmphibieConstruct`) :**
- Création avec 6 places → Exception `invalid_argument` (contrainte Voiture)
- Création avec bateau à 350 km/h → Exception `invalid_argument` (contrainte Bateau)
- Création avec plus d'occupants que de places → Exception `invalid_argument`
- Création valide (180 km/h sur route, 80 km/h sur eau, 4 places, 2 occupants) → Succès

### Méthode afficherAttributs

```cpp
void afficherAttributs() const
```

**Méthode spécifique à VoitureAmphibie** qui illustre la présence des doubles attributs.

Affiche séparément :
- Les attributs hérités via `Voiture` (accès via `Voiture::vitesse_`, `Voiture::vitesseMax_`, etc.)
- Les attributs hérités via `Bateau` (accès via `Bateau::vitesse_`, `Bateau::vitesseMax_`, etc.)

**Tests (`testVoitureAmphibieAfficherAttributs`) :**
- Affichage après création : les deux modes ont les mêmes valeurs initiales
- Accélération du mode voiture à 50 km/h et du mode bateau à 30 km/h
- Affichage après modifications : démontre que les attributs sont bien distincts et peuvent avoir des valeurs différentes

### Méthode demarrer

```cpp
virtual void demarrer()
```

Démarre **les deux modes** simultanément (voiture ET bateau) en appelant `Voiture::demarrer()` et `Bateau::demarrer()`.

**Tests (`testVoitureAmphibieDemarrer`) :**
- Démarrage normal → Démarre les 2 modes avec succès
- Tentative de redémarrage → Les 2 modes sont déjà en marche
- Test avec mode voiture en panne → Le mode bateau démarre mais pas le mode voiture

### Méthode arreter

```cpp
virtual void arreter()
```

Arrête **les deux modes** simultanément en appelant `Voiture::arreter()` et `Bateau::arreter()`.

**Tests (`testVoitureAmphibieArreter`) :**
- Tentative d'arrêt avec vitesses non nulles (80 km/h voiture, 50 km/h bateau) → Échec pour les 2 modes
- Freinage complet des deux modes puis arrêt → Succès
- Tentative d'arrêt alors que déjà arrêté → Exception pour les 2 modes

### Méthode testVoitureAmphibieModesIndependants

Ce test démontre l'**indépendance complète des deux modes** :

**Scénario du test :**
1. Démarrage du mode voiture uniquement et accélération à 120 km/h
2. Démarrage du mode bateau séparément et accélération à 60 km/h
3. Arrêt du mode voiture seulement (freinage puis arrêt)
4. Mise en panne du mode bateau seulement
5. Affichage final montrant :
   - Mode voiture : ARRET, vitesse 0 km/h
   - Mode bateau : PANNE_SEVERE, vitesse 60 km/h

**Conclusion :** Les deux modes peuvent être contrôlés et manipulés de manière totalement indépendante, chacun avec ses propres attributs d'état, de vitesse, etc.

### Destructeur ~VoitureAmphibie

```cpp
virtual ~VoitureAmphibie()
```

Détruit la voiture amphibie en affichant un message de confirmation.

---

## Conclusion

Ce projet démontre :
1. **L'héritage simple** avec `Voiture` et `Bateau` héritant de `Vehicule`
2. **L'héritage multiple** avec `VoitureAmphibie` héritant de `Voiture` et `Bateau`
3. **Le problème du diamant** : `VoitureAmphibie` possède deux instances des attributs de `Vehicule`
4. **La gestion d'états complexes** avec des contraintes spécifiques à chaque classe
5. **Les tests exhaustifs** validant tous les cas nominaux et d'erreur

Les tests unitaires dans `main.cpp` couvrent l'ensemble des fonctionnalités et cas limites, garantissant la robustesse de l'implémentation.