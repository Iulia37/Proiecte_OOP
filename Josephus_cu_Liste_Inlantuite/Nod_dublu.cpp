#include <iostream>
#include "Nod_dublu.h"

using namespace std;

Nod_dublu::Nod_dublu(): Nod(), ante(nullptr) {}

Nod_dublu::Nod_dublu(int info): Nod(info), ante(nullptr) {}

Nod_dublu::Nod_dublu(int info, Nod* next, Nod_dublu* ante): Nod(info, next), ante(ante) {}

Nod_dublu::Nod_dublu(const Nod_dublu& nod): Nod(nod)
{
    this -> ante = nod.ante;
}

void Nod_dublu::SetAnte(Nod_dublu* ante)
{
    this -> ante = ante;
}

void Nod_dublu::SetNext(Nod_dublu* next)
{
    this -> next = next;

}

Nod_dublu& Nod_dublu::operator=(const Nod_dublu& nod)
{
    if(this != &nod)
    {
        SetNext(nullptr);
        delete next;
        if(nod.next == nullptr)
            SetNext(nullptr);
        else
            SetNext(new Nod_dublu(*nod.GetNext()));

        SetInfo(nod.info);

        ante = nullptr;
        delete ante;
        if(nod.ante == nullptr)
            this -> ante = nullptr;
        else
            this -> ante = new Nod_dublu(*nod.ante);
    }
    return *this;
}

istream& operator>>( istream& in, Nod_dublu& nod)
{
    if(nod.next)
    {
        nod.next = nullptr;
        delete nod.next;
    }
    if(nod.ante)
    {
        nod.ante = nullptr;
        delete nod.ante;
    }
    nod.info = 0;
    cout<<"Valoarea din nod este: ";
    in>>nod.info;

    return in;
}

ostream& operator<<( ostream& out, const Nod_dublu nod)
{
    out<<"Valoarea din nod este: "<<nod.info<<'\n';
    out<<"Nodul urmator se afla la adresa: "<<nod.next<<'\n';
    out<<"Nodul anterior se afla la adresa: "<<nod.ante<<'\n';
    out<<'\n';
    return out;
}

Nod_dublu::~Nod_dublu()
{
    ante = nullptr;
    delete ante;
}
