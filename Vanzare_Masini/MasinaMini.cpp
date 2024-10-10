#include "MasinaMini.h"
using namespace std;

MasinaMini::MasinaMini(): Masina() {};

MasinaMini::MasinaMini(string marca, string model, int an_fabricatie, double pret, double lungime):
    Masina(marca, model, an_fabricatie, pret, lungime)
{
    ///cout<<"Constructor MasinaMini\n";
};

MasinaMini& MasinaMini::operator=(const MasinaMini& masina)
{
    if(this != &masina)
        Masina::operator=(masina);
    else
        return *this;
}

istream& operator>>(istream& in, MasinaMini& masina)
{
    in>>static_cast<Masina&>(masina);
    return in;
}

ostream& operator<<(ostream& out, const MasinaMini& masina)
{
    out<<static_cast<const Masina&>(masina);
    return out;
}

MasinaMini::~MasinaMini()
{
    ///cout<<"Destructor MasinaMini\n";
}
