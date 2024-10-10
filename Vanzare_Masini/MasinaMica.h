#ifndef MASINAMICA_H
#define MASINAMICA_H

#include<iostream>
#include "Masina.h"
using namespace std;

class MasinaMica:public Masina
{
public:
    MasinaMica();
    MasinaMica(string marca, string model, int an_fabricatie, double pret, double lungime);

    ~MasinaMica();

    void Afisare() const { Masina::Afisare(); };
    double CalcularePret() const override { return GetPret(); };

    MasinaMica& operator=(const MasinaMica& masina);
    friend istream& operator>>(istream& in, MasinaMica& masina);
    friend ostream& operator<<(ostream& out, const MasinaMica& masina);
};

#endif // MASINAMINI_H

