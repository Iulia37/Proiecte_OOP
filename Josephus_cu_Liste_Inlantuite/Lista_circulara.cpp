#include <iostream>
#include "Lista_circulara.h"
using namespace std;

Lista_circulara::Lista_circulara(): Lista() {};

Lista_circulara::Lista_circulara(int size): Lista(size)
{
    Nod_dublu* temp = new Nod_dublu;        ///lista circulara se construieste ca cea din clasa de baza
    Nod_dublu* temp2 = new Nod_dublu;       ///in plus avem ca first este next pentru last, iar last este
    temp = this -> GetFirst();              ///anterior pentru first
    temp2 = this -> GetLast();
    temp -> SetAnte(temp2);
    temp2 -> SetNext(temp);
}

Lista_circulara::Lista_circulara(const Lista_circulara& lista)
{
    this -> size = 0;
    this -> first = nullptr;
    this -> last = nullptr;
    if (lista.first != nullptr)
    {
        Nod_dublu* temp = lista.first;
        AddToEnd(temp -> GetInfo());
        temp = temp -> GetNext();
        while (temp != lista.first)
        {
            AddToEnd(temp -> GetInfo());
            temp = temp -> GetNext();
        }
    }
};

void Lista_circulara::AddToBegin(int info)
{
    Lista::AddToBegin(info);            ///folosesc metoda din clasa de baza

    Nod_dublu* temp = new Nod_dublu;    ///si ma asigur ca lista isi pastreaza proprietatea de circularitate
    Nod_dublu* temp2 = new Nod_dublu;

    temp = this -> GetFirst();
    temp2 = this -> GetLast();

    temp -> SetAnte(temp2);
    temp2 -> SetNext(temp);
}

void Lista_circulara::AddToEnd(int info)
{
    Lista::AddToEnd(info);

    Nod_dublu* temp = new Nod_dublu;
    Nod_dublu* temp2 = new Nod_dublu;

    temp = this -> GetFirst();
    temp2 = this -> GetLast();

    temp -> SetAnte(temp2);
    temp2 -> SetNext(temp);
}

Lista_circulara& Lista_circulara::operator=(const Lista_circulara& lista)
{
    if(this != &lista)
    {
        if(GetFirst())
        {
            Nod_dublu *current = GetFirst();
            Nod_dublu *temp = nullptr;

            while (current != nullptr)
            {
                temp = current;
                temp -> SetNext();
                temp -> SetAnte();
                current = current->GetNext();
                delete temp;
            }
        }
        size = 0;
        Nod_dublu* temp = lista.GetFirst();
        while(temp)
        {
            int val = temp -> GetInfo();
            this -> AddToEnd(val);
            temp = temp -> GetNext();
        }
    }
    else
        return *this;
}

istream& operator>>(istream& in, Lista_circulara& lista)
{
    if(lista.GetFirst())
    {
        Nod_dublu *current = lista.GetFirst();
        Nod_dublu *temp = nullptr;

        while (current != nullptr)
        {
            temp = current;
            temp -> SetNext();
            temp -> SetAnte();
            current = current->GetNext();
            delete temp;
        }
    }
    lista.size = 0;
    cout<<"Dimensiunea listei circulare: ";
    in>>lista.size;
    int n = lista.size;
    cout<<"Elementele listei: ";
    for(int i = 0; i < n; i++)
    {
        int info;
        in>>info;
        lista.AddToEnd(info);
    }
    lista.size -= n;
    return in;
}

ostream& operator<<(ostream& out, const Lista_circulara& lista)
{
    Nod_dublu* iterator = lista.GetFirst();
    cout<<"Lista are "<<lista.size<<" elemente: ";
    for(int i = 0; i < lista.GetSize(); i++)
    {
        out<<iterator -> GetInfo()<<" ";
        iterator = iterator -> GetNext();
    }
    out<<'\n'<<'\n';
    return out;
}

Lista_circulara::~Lista_circulara()
{
    Nod_dublu *current = GetFirst();
    Nod_dublu *temp = nullptr;

    while (current != nullptr)
    {
        temp = current;
        temp -> SetNext();
        temp -> SetAnte();
        current = current->GetNext();
        delete temp;
    }
    size = 0;
}
