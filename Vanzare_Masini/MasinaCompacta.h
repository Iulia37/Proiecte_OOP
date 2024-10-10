#ifndef MASINA_COMPACTA_H
#define MASINA_COMPACTA_H

#include <iostream>
#include "Masina.h"
using namespace std;

class MasinaCompacta: public Masina
{
public:
    MasinaCompacta();
    MasinaCompacta(string marca, string model, int an_fabricatie, double pret, double lungime);

    ~MasinaCompacta();

    void Afisare() const { Masina::Afisare(); };
    double CalcularePret() const override { return GetPret(); };

    MasinaCompacta& operator=(const MasinaCompacta& masina);
    friend istream& operator>>(istream& in, MasinaCompacta& masina);
    friend ostream& operator<<(ostream& out, const MasinaCompacta& masina);
};

#endif // MASINA_COMPACTA_H
