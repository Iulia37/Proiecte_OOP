#ifndef MASINA_H
#define MASINA_H

#include <iostream>
using namespace std;

class Masina
{
    static int ID;
    const int IDmasina;
    string marca;
    string model;
    int an_fabricatie;
    double pret;
    double lungime;

public:
    Masina();
    Masina(string marca, string model, int an_fabricatie, double pret, double lungime);

    Masina(const Masina& masina);

    virtual ~Masina();

    static int GenerareID() { return ID++; };

    int GetID() const { return IDmasina; };

    const string GetMarca() const;

    const string GetModel() const;

    int GetAnFabricatie() const;

    double GetPret() const;
    void SetPret(double pret);

    double GetLungime() const;

    virtual void Afisare() const;
    virtual istream& Citire(istream& in);

    virtual double CalcularePret() const = 0;

    bool operator<(const Masina& masina) const
    {
        return pret < masina.pret; /// Comparare după preț
    }

    Masina& operator=(const Masina& masina);
    friend istream& operator>>(istream& in, Masina& masina) { return masina.Citire(in); };
    friend ostream& operator<<(ostream& out, const Masina& masina);
};


#endif // MASINA_H
