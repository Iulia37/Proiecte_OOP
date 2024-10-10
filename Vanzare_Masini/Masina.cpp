#include <iostream>
#include <exception>
#include "Masina.h"
using namespace std;

int Masina::ID = 0;

Masina::Masina(): IDmasina(GenerareID()), marca("Necunoscut"), model("Necunoscut"), an_fabricatie(0), pret(0),lungime(0){};

Masina::Masina(string marca, string model, int an_fabricatie, double pret, double lungime):
    IDmasina(GenerareID()), marca(marca), model(model), an_fabricatie(an_fabricatie), pret(pret),lungime(lungime)
{
    ///cout<<"Constructor Masina\n";
};

Masina::Masina(const Masina& masina): IDmasina(GenerareID())
{
    this -> marca = masina.marca;
    this -> model = masina.model;
    this -> an_fabricatie = masina.an_fabricatie;
    this -> pret = masina.pret;
    this -> lungime = masina.lungime;
}

const string Masina::GetMarca() const { return marca; }

const string Masina::GetModel() const { return model; }

int Masina::GetAnFabricatie() const{  return an_fabricatie; }

double Masina::GetPret() const {  return pret; }

void Masina::SetPret(double pret) {  this -> pret = pret; }

double Masina::GetLungime() const{  return lungime; }

void Masina::Afisare() const
{
    cout<<"ID: "<<IDmasina<<'\n'
        <<"Marca: "<<marca<<'\n'
        <<"Model: "<<model<<'\n'
        <<"Anul Fabricatiei: "<<an_fabricatie<<'\n'
        <<"Pret: "<<pret<<'\n'
        <<"Lungime: "<<lungime<<'\n'<<'\n';
}

istream& Masina::Citire(istream& in)
{
    cout<<"Intordu Marca: ";
    in>>this -> marca;
    cout<<"Introdu Modelul: ";
    in>>this -> model;
    cout<<"Introdu Anul Fabricatiei: ";
    in>>this -> an_fabricatie;

    cout<<"Introdu Pretul (euro): ";
    in>>this -> pret;
    if(this -> pret < 0)
    {
        cout<<"Input invalid\n";
        this -> pret = 0;
    }

    cout<<"Introdu Lungimea: ";
    in>>this -> lungime;
    if(this -> lungime < 0)
    {
        cout<<"Input invalid\n";
        this -> lungime = 0;
    }
    cout<<'\n';
    return in;
}

Masina& Masina::operator=(const Masina& masina)
{
    if(this != &masina)
    {
        model = masina.model;
        marca = masina.marca;
        an_fabricatie = masina.an_fabricatie;
        pret = masina.pret;
        lungime = masina.lungime;
    }
    else
        return *this;
}

ostream& operator<<(ostream& out, const Masina& masina)
{
     out<<"ID: "<<masina.IDmasina<<'\n'
        <<"Marca: "<<masina.marca<<'\n'
        <<"Model: "<<masina.model<<'\n'
        <<"Anul Fabricatiei: "<<masina.an_fabricatie<<'\n'
        <<"Pret: "<<masina.pret<<" euro"<<'\n'
        <<"Lungime: "<<masina.lungime<<'\n'<<'\n';
     return out;
}

Masina::~Masina()
{
    ///cout<<"Destructor Masina\n";
}
