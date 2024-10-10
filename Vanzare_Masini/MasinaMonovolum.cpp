#include "MasinaMonovolum.h"
using namespace std;

MasinaMonovolum::MasinaMonovolum(): nou(true), Masina() {};

MasinaMonovolum::MasinaMonovolum(bool nou, string marca, string model, int an_fabricatie, double pret, double lungime):
    nou(nou), Masina(marca, model, an_fabricatie, pret, lungime)
{
    ///cout<<"Constructor MasinaMonovolum\n";
};

MasinaMonovolum& MasinaMonovolum::operator=(const MasinaMonovolum& masina)
{
    if(this != &masina)
    {
        Masina::operator=(masina);
        nou = masina.nou;
    }
    else
        return *this;
}

istream& operator>>(istream& in, MasinaMonovolum& masina)
{
    cout<<"Masina noua (true - 1/false - 0): ";
    in>>masina.nou;
    in>>static_cast<Masina&>(masina);
    cout<<'\n';
    return in;
}

ostream& operator<<(ostream& out, const MasinaMonovolum& masina)
{
    out<<"Masina noua: "<<(masina.nou ? "Da" : "Nu")<<'\n';
    out<<static_cast<const Masina&>(masina);
    return out;
}

MasinaMonovolum::~MasinaMonovolum()
{
    ///cout<<"Destructor MasinaMonovolum\n";
}
