#include <iostream>
#include "Nod.h"
using namespace std;

Nod::Nod(): info(0), next(nullptr) {}

Nod::Nod(int info): info(info), next(nullptr) {}

Nod::Nod(int info, Nod* next): info(info), next(next) {}

Nod::Nod(const Nod &nod)
{
    this -> info = nod.info;
    this -> next = nod.next;
}

void Nod::SetInfo(int info)
{
    this -> info = info;
}

void Nod::SetNext(Nod *next)
{
    this -> next = next;
}

Nod& Nod::operator=(const Nod& nod)
{
    if(this != &nod)
    {
        next = nullptr;
        delete next;
        if(nod.next == nullptr)
            this -> next = nullptr;
        else
            this -> next = new Nod(*nod.next);
        this -> info = nod.info;
    }
    return *this;
}

istream& operator>>( istream& in, Nod& nod)
{
    if(nod.next)
    {
        nod.next = nullptr;
        delete nod.next;
    }
    nod.info = 0;
    cout<<"Valoarea din nod este: ";
    in>>nod.info;
    return in;
}

ostream& operator<<( ostream& out, const Nod nod)
{
    out<<"Valoarea din nod este: "<<nod.info<<'\n';
    out<<"Nodul urmator se afla la adresa: "<<nod.next<<'\n';
    out<<'\n';
    return out;
}

Nod::~Nod()
{
    next = nullptr;
    delete next;
    info = 0;
}
