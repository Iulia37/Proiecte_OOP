#ifndef NOD_DUBLU_H
#define NOD_DUBLU_H

#include <iostream>
#include "Nod.h"
using namespace std;

class Nod_dublu: public Nod
{
    Nod_dublu *ante;

public:

    ///constructori cu si fara parametrii
    Nod_dublu();    ///initializeaza valoarea din nod cu 0, next si ante cu NULL
    Nod_dublu(int info);
    Nod_dublu(int info, Nod* next, Nod_dublu* ante);    ///initializeaza info, next si ante cu valoarile date ca parametrii

    ~Nod_dublu();   ///destructorul

    Nod_dublu (const Nod_dublu& nod); ///copy constructorul

    Nod_dublu* GetNext() const { return static_cast<Nod_dublu*>(Nod::GetNext()); };  ///returneaza adresa nodului urmator
    Nod_dublu* GetAnte() const { return ante; };    ///returneaza adresa nodului anterior

    void SetAnte(Nod_dublu* ante = nullptr);     ///inlocuieste anteriorul cu ante (noul anterior)
    void SetNext(Nod_dublu* next = nullptr);

    Nod_dublu& operator=(const Nod_dublu& nod);
    friend istream& operator>>( istream& in, Nod_dublu& nod);
    friend ostream& operator<<( ostream& out, const Nod_dublu nod);
};

#endif // NOD_DUBLU_H
