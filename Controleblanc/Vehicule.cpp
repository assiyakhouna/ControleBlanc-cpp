
#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    string immatriculation;
    string marque;
    double vitesseMax;

public:
    Vehicule(string imm, string m, double v) {
        immatriculation = imm;
        marque = m;
        vitesseMax = v;
    }

    virtual void afficherDetails() {
        cout << "Immatriculation : " << immatriculation << endl;
        cout << "Marque : " << marque << endl;
        cout << "Vitesse maximale : " << vitesseMax << endl;
    }

    virtual ~Vehicule() {}
};

class Voiture : public Vehicule {
private:
    int nombrePortes;
    string typeCarburant;

public:
    Voiture(string imm, string m, double v,
            int portes, string carburant)
        : Vehicule(imm, m, v) {
        nombrePortes = portes;
        typeCarburant = carburant;
    }

    void afficherDetails() override {
        cout << "\n--- Voiture ---" << endl;
        cout << "Immatriculation : " << immatriculation << endl;
        cout << "Marque : " << marque << endl;
        cout << "Vitesse maximale : " << vitesseMax << endl;
        cout << "Nombre de portes : " << nombrePortes << endl;
        cout << "Type de carburant : " << typeCarburant << endl;
    }
};

class Camion : public Vehicule {
private:
    double capaciteCharge;
    int nombreEssieux;

public:
    Camion(string imm, string m, double v,
           double capacite, int essieux)
        : Vehicule(imm, m, v) {
        capaciteCharge = capacite;
        nombreEssieux = essieux;
    }

    void afficherDetails() override {
        cout << "\n--- Camion ---" << endl;
        cout << "Immatriculation : " << immatriculation << endl;
        cout << "Marque : " << marque << endl;
        cout << "Vitesse maximale : " << vitesseMax << endl;
        cout << "Capacite de charge : " << capaciteCharge << endl;
        cout << "Nombre d'essieux : " << nombreEssieux << endl;
    }
};

int main() {
    Voiture v1("123-A-45", "Toyota", 180, 5, "Essence");
    Camion c1("456-B-78", "Volvo", 120, 20.5, 4);

    Vehicule* tab[2];
    tab[0] = &v1;
    tab[1] = &c1;

    for (int i = 0; i < 2; i++) {
        tab[i]->afficherDetails();
    }

    return 0;
}
