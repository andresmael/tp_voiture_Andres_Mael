#pragma once

#include <string>

class CVoiture {
private:
    std::string marque;
    std::string modele;
    int puissance;
    std::string carburant;
    int vitesse;
    bool moteurDemarre;

public:
    CVoiture(std::string marque, std::string modele, int puissance, std::string carburant);
    void afficherInfos() const;
    void demarrer();
    void accelerer(int kmh);
    void ralentir(int kmh);
    void arreter();
};
