#pragma once

#include <string>

class CRoue {
private:
    std::string marque;
    std::string modele;
    int pression;
    int diametre;
    bool aCreve; // renommé pour éviter conflit avec méthode crever()

public:
    CRoue(std::string marque, std::string modele, int diametre);
    void gonfler(int bar);
    void degonfler(int bar);
    void crever();
    int getPression() const;
    bool estCrevee() const;
    std::string getInfo() const;
};

class CVoiture {
private:
    std::string marque;
    std::string modele;
    int puissance;
    std::string carburant;
    int vitesse;
    bool moteurDemarre;
    CRoue roues[4]; // les 4 roues

public:
    CVoiture(std::string marque, std::string modele, int puissance, std::string carburant,
             std::string roueMarque, std::string roueModele, int roueDiametre);
    void afficherInfos() const;
    void demarrer();
    void accelerer(int kmh);
    void ralentir(int kmh);
    void arreter();
    void afficherRoues() const;
    void controlerPressionRoues() const;
    CRoue& getRoue(int index); // accès à une roue par index (0-3)
};
