#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nod_dublu.h"

using namespace std;

class Lista
{
protected:

    Nod_dublu *first;
    Nod_dublu *last;
    int size;

public:
    ///constructori cu si fara parametrii
    Lista();    ///initializare lista vida
    Lista(int size);    ///initializare lista cu size elemente de tip Nod_dublu

    Lista(const Lista& lista);  ///copy constructorul

    int GetSize() const { return size; };

    Nod_dublu* GetFirst() const     ///returneaza adresa primului nod
    {
        if(first == nullptr)
            return nullptr;
        else
            return first;
    };

    Nod_dublu* GetLast() const      ///returneaza adresa ultimului nod
    {
        if(last == nullptr)
            return nullptr;
        else
            return last;
    };

    //void SetFirst(Nod_dublu* new_first) { first = new_first; };
    //void SetLast(Nod_dublu* new_last) { last = new_last; };

    virtual void AddToBegin(int info);  ///adauga un nod la inceputul listei
    virtual void AddToEnd(int info);    ///adauga un nod la finalul listei
    void Remove(Nod_dublu* nod);    ///sterge un nod transmis ca parametru din lista

    Lista& operator=(const Lista& lista);
    friend istream& operator>>(istream& in, Lista& lista);
    friend ostream& operator<<(ostream& out, const Lista& lista);

    virtual ~Lista();
};

#endif // LISTA_H
