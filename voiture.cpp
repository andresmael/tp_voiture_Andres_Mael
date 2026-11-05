#include "voiture.h"
#include <iostream>

using namespace std;

// ==================== CRoue ====================

CRoue::CRoue(string marque, string modele, int diametre)
    : marque(marque), modele(modele), pression(2), diametre(diametre), aCreve(false) {}

void CRoue::gonfler(int bar) {
    pression += bar;
}

void CRoue::degonfler(int bar) {
    pression -= bar;
    if (pression < 0) pression = 0;
}

void CRoue::crever() {
    pression = 0;
    aCreve = true;
}

int CRoue::getPression() const {
    return pression;
}

bool CRoue::estCrevee() const {
    return aCreve;
}

string CRoue::getInfo() const {
    string etat = aCreve ? "CREVEE" : "OK";
    return marque + " " + modele + " (" + to_string(diametre) + '")'
         + " - Pression : " + to_string(pression) + " bar [" + etat + "]";
}

// ==================== CVoiture ====================

CVoiture::CVoiture(string marque, string modele, int puissance, string carburant,
                   string roueMarque, string roueModele, int roueDiametre)
    : marque(marque), modele(modele), puissance(puissance), carburant(carburant),
      vitesse(0), moteurDemarre(false),
      roues{ CRoue(roueMarque, roueModele, roueDiametre),
             CRoue(roueMarque, roueModele, roueDiametre),
             CRoue(roueMarque, roueModele, roueDiametre),
             CRoue(roueMarque, roueModele, roueDiametre) } {}

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

void CVoiture::afficherRoues() const {
    cout << "=== Roues ===" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Roue " << (i + 1) << " : " << roues[i].getInfo() << endl;
    }
    cout << "=============" << endl << endl;
}

void CVoiture::controlerPressionRoues() const {
    for (int i = 0; i < 4; i++) {
        if (roues[i].estCrevee()) {
            cout << "Alerte : la roue " << (i + 1) << " est crevée !" << endl;
        } else if (roues[i].getPression() < 2) {
            cout << "Attention : pression basse sur la roue " << (i + 1)
                 << " (" << roues[i].getPression() << " bar)" << endl;
        }
    }
}

CRoue& CVoiture::getRoue(int index) {
    return roues[index];
}
