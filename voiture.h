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

class CRoue {
private:
    std::string marque;
    std::string modele;
    int pression;
    int diametre;
    bool crever;

public:
    CRoue(std::string marque, std::string modele, int diametre);
    void gonfler(int bar);
    void degonfler(int bar);
    void crever();
};
