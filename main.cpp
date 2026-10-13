#include <iostream>
#include "voiture.h"

using namespace std;

int main() {
    cout << "========== TP Voiture ==========" << endl << endl;

    CVoiture voiture("Peugeot", "208", 100, "Essence");

    voiture.afficherInfos();

    voiture.demarrer();

    voiture.accelerer(50);
    voiture.afficherInfos();

    voiture.ralentir(20);
    voiture.afficherInfos();

    voiture.arreter();
    voiture.afficherInfos();

    cout << "========== Fin du programme ==========" << endl;

    return 0;
}
