#ifndef VANZARE_H
#define VANZARE_H

#include<iostream>
#include<set>
#include<typeinfo>
#include "Masina.h"
#include "MasinaMonovolum.h"
using namespace std;

template < class Type >
class Vanzare
{
    int nr_stoc;
    int nr_vandute;
    set< pair< Type*, bool> >masini_stoc;
    set< pair< Type*, bool> >masini_vandute;

public:
    Vanzare() { nr_stoc = 0; nr_vandute = 0; }

    int GetNrStoc() { return nr_stoc; }
    int GetNrVandute() { return nr_vandute; }

    const set<pair<Type*, bool>>& GetMasiniStoc() const {
        return masini_stoc;
    }

    void Vanzare_masina(Type* masina)
    {
        bool e_nou = true;
        MasinaMonovolum* monovolum = dynamic_cast<MasinaMonovolum*>(masina);
        if(monovolum)
        {
            e_nou = monovolum -> GetNou();
            int pret_nou = monovolum -> CalcularePret();
            masina -> SetPret(pret_nou);
        }

        pair< Type*, bool> pereche = make_pair(masina, e_nou);

        typename set< pair< Type*, bool> >::iterator it;

        it = masini_stoc.find(pereche);
        if(it != masini_stoc.end())
        {
            masini_stoc.erase(it);
            nr_stoc--;
            masini_vandute.insert(pereche);
            nr_vandute++;
        }
        else
            cout<<"Masina nu se afla in stoc\n";

    }
    void AddStoc (Type* masina)
    {
        bool e_nou = true;
        MasinaMonovolum* monovolum = dynamic_cast<MasinaMonovolum*>(masina);
        if(monovolum)
            e_nou = monovolum -> GetNou();

        pair< Type*, bool> pereche = make_pair(masina, e_nou);
        masini_stoc.insert(pereche);
        nr_stoc++;
    }
    void AfisareStoc() const
    {
        typename set< pair< Type*, bool> >::iterator it;

        cout<<"Masinile din stoc sunt: \n\n";
        for(const auto& masina: masini_stoc)
        {
            masina.first -> Afisare();
        }
    }

    void AfisareVanzari() const
    {
        typename set< pair< Type*, bool> >::iterator it;

        cout<<"Masinile vandute sunt: \n\n";
        for(const auto& masina: masini_vandute)
        {
            masina.first -> Afisare();
        }
    }

    void operator-=(Type* masina)
    {
        Vanzare_masina(masina);
    }

    ~Vanzare()
    {
        for(auto& masina:masini_stoc)
            delete masina.first;

        for(auto& masina:masini_vandute)
            delete masina.first;
    }
};

template<>
class Vanzare<MasinaMonovolum>
{
    int nr_stoc;
    int nr_vandute;
    set< pair< MasinaMonovolum, bool> >masini_stoc;
    set< pair< MasinaMonovolum, bool> >masini_vandute;

public:
    int GetNrStoc() const { return nr_stoc; }
    int GetNrVandute() const { return nr_vandute; }

    void Vanzare_masina(MasinaMonovolum masina)
    {
        masina.SetPret(masina.CalcularePret());
        pair< MasinaMonovolum, bool> pereche = make_pair(masina, masina.GetNou());
        typename set< pair< MasinaMonovolum, bool> >::iterator it;

        it = masini_stoc.find(pereche);
        if(it != masini_stoc.end())
        {
            masini_stoc.erase(it);
            nr_stoc--;
            masina.SetPret(masina.CalcularePret());
            masini_vandute.insert(pereche);
            nr_vandute++;
        }
        else
            cout<<"Masina nu se afla in stoc\n";

    }
    void AddStoc (MasinaMonovolum masina)
    {
        pair< MasinaMonovolum, bool> pereche = make_pair(masina, masina.GetNou());
        masini_stoc.insert(pereche);
        nr_stoc++;
    }
    void AfisareStoc() const
    {
        typename set< pair< MasinaMonovolum, bool> >::iterator it;

        cout<<"Masinile din stoc sunt: \n\n";
        for(it = masini_stoc.begin(); it != masini_stoc.end(); it++)
        {
            cout<<it -> first;
        }
    }

    void AfisareVanzari() const
    {
        typename set< pair< MasinaMonovolum, bool> >::iterator it;

        cout<<"Masinile vandute sunt: \n\n";
        for(it = masini_vandute.begin(); it != masini_vandute.end(); it++)
        {
            cout<<it -> first;
        }
    }
};

#endif // VANZARE_H
