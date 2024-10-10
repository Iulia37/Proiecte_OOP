#include "MasinaMica.h"
using namespace std;

MasinaMica::MasinaMica(): Masina() {};

MasinaMica::MasinaMica(string marca, string model, int an_fabricatie, double pret, double lungime):
    Masina(marca, model, an_fabricatie, pret, lungime)
{
    ///cout<<"Constructor MasinaMica\n";
};

MasinaMica& MasinaMica::operator=(const MasinaMica& masina)
{
    if(this != &masina)
        Masina::operator=(masina);
    else
        return *this;
}

istream& operator>>(istream& in, MasinaMica& masina)
{
    in>>static_cast<Masina&>(masina);
    return in;
}

ostream& operator<<(ostream& out, const MasinaMica& masina)
{
    out<<static_cast<const Masina&>(masina);
    return out;
}

MasinaMica::~MasinaMica()
{
    ///cout<<"Destructor MasinaMica\n";
}
