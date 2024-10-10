#include "MasinaCompacta.h"
using namespace std;

MasinaCompacta::MasinaCompacta(): Masina() {};

MasinaCompacta::MasinaCompacta(string marca, string model, int an_fabricatie, double pret, double lungime):
    Masina(marca, model, an_fabricatie, pret, lungime)
{
    ///cout<<"Constructor MasinaCompacta\n";
};

MasinaCompacta& MasinaCompacta::operator=(const MasinaCompacta& masina)
{
    if(this != &masina)
        Masina::operator=(masina);
    else
        return *this;
}

istream& operator>>(istream& in, MasinaCompacta& masina)
{
    in>>static_cast<Masina&>(masina);
    return in;
}

ostream& operator<<(ostream& out, const MasinaCompacta& masina)
{
    out<<static_cast<const Masina&>(masina);
    return out;
}

MasinaCompacta::~MasinaCompacta()
{
    ///cout<<"Destructor MasinaCompacta\n";
}
