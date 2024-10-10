#ifndef MASINAMONOVOLUM_H
#define MASINAMONOVOLUM_H

#include<iostream>
#include "Masina.h"
using namespace std;

class MasinaMonovolum: public Masina
{
    bool nou;

public:
    MasinaMonovolum();
    MasinaMonovolum(bool nou, string marca, string model, int an_fabricatie, double pret, double lungime);

    ~MasinaMonovolum();

    bool GetNou() const { return nou; }

    void Afisare() const { cout<<"Masina noua: "<<(nou ? "Da" : "Nu")<<'\n'; Masina::Afisare(); } ;
    double CalcularePret() const override
    {
        int an_curent;
        bool vara;
        cout<<"Introduceti anul curent: ";
        cin>>an_curent;
        cout<<"Este vara? (0/1): ";
        cin>>vara;
        double pret_final = GetPret();
        if(!nou)
        {
            int vechime = an_curent - GetAnFabricatie();
            pret_final -= pret_final*vechime*0.025;
            if(vara)
                pret_final = pret_final * 0.9;
        }
        return pret_final;
    };

    MasinaMonovolum& operator=(const MasinaMonovolum& masina);
    friend istream& operator>>(istream& in, MasinaMonovolum& masina);
    friend ostream& operator<<(ostream& out, const MasinaMonovolum& masina);
};

#endif // MASINAMONOVOLUM_H


