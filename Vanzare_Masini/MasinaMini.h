#ifndef MASINAMINI_H
#define MASINAMINI_H

#include<iostream>
#include "Masina.h"
using namespace std;

class MasinaMini:public Masina
{
public:
    MasinaMini();
    MasinaMini(string marca, string model, int an_fabricatie, double pret, double lungime);

    ~MasinaMini();

    void Afisare() const { Masina::Afisare(); };
    double CalcularePret() const override { return GetPret(); };

    MasinaMini& operator=(const MasinaMini& masina);
    friend istream& operator>>(istream& in, MasinaMini& masina);
    friend ostream& operator<<(ostream& out, const MasinaMini& masina);
};

#endif // MASINAMINI_H
