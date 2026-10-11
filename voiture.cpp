#include "voiture.h"
#include <iostream>

using namespace std;

CVoiture::CVoiture(string marque, string modele, int puissance, string carburant)
    : marque(marque), modele(modele), puissance(puissance), carburant(carburant),
      vitesse(0), moteurDemarre(false) {}

void CVoiture::afficherInfos() const {
    cout << "=== Informations du véhicule ===" << endl;
    cout << "Marque : " << marque << endl;
    cout << "Modèle : " << modele << endl;
    cout << "Puissance : " << puissance << " ch" << endl;
    cout << "Carburant : " << carburant << endl;
    cout << "Vitesse : " << vitesse << " km/h" << endl;
    cout << "Moteur : " << (moteurDemarre ? "Allumé" : "Éteint") << endl;
    cout << "=============================== " << endl << endl;
}

void CVoiture::demarrer() {
    if (moteurDemarre) {
        cout << "Le moteur est déjà démarré." << endl << endl;
    } else {
        moteurDemarre = true;
        cout << "Le moteur de la " << marque << " " << modele << " est démarré." << endl << endl;
    }
}

void CVoiture::accelerer(int kmh) {
    if (!moteurDemarre) {
        cout << "Impossible d'accélérer : le moteur n'est pas démarré !" << endl << endl;
        return;
    }
    vitesse += kmh;
    cout << "Accélération de " << kmh << " km/h. Vitesse : " << vitesse << " km/h." << endl << endl;
}

void CVoiture::ralentir(int kmh) {
    if (!moteurDemarre) {
        cout << "Impossible de ralentir : le moteur n'est pas démarré !" << endl << endl;
        return;
    }
    vitesse -= kmh;
    if (vitesse < 0) vitesse = 0;
    cout << "Ralentissement de " << kmh << " km/h. Vitesse : " << vitesse << " km/h." << endl << endl;
}

void CVoiture::arreter() {
    if (!moteurDemarre) {
        cout << "Le moteur est déjà arrêté." << endl << endl;
    } else {
        vitesse = 0;
        moteurDemarre = false;
        cout << "Le moteur est arrêté." << endl << endl;
    }
}
