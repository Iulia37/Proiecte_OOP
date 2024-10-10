#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista(): size(0), first(nullptr), last(nullptr) {}

Lista::Lista(int size): size(size)
{
    first = new Nod_dublu;  ///primul nod este first
    Nod_dublu *iterator = first;
    Nod_dublu *iterator2 = first;
    first -> SetAnte();     ///primul nod nu are anterior => nullptr
    for(int i = 0; i < size - 1; i++)
    {
        Nod_dublu *temp = new Nod_dublu;    ///la fiecare pas adaugam un nou nod in lista si ii setam
        iterator -> SetNext(temp);          ///anteriorul si nextul
        iterator = temp;
        iterator -> SetAnte(iterator2);
        iterator2 = iterator;
        last = iterator;    ///tinem minte ultimul nod
    }
}

Lista::Lista(const Lista& lista): size(0), first(nullptr), last(nullptr)
{
    if (lista.first != nullptr)
    {
        Nod_dublu* temp = lista.first;
        while (temp != nullptr)
        {
            AddToEnd(temp -> GetInfo());
            temp = temp -> GetNext();
        }
    }
}

void Lista::AddToBegin(int info)
{
    Nod_dublu* nod = new Nod_dublu;
    nod -> SetInfo(info);
    if(GetFirst() == nullptr)    ///daca lista este goala, nodul pe care dorim sa il
    {                               ///adaugam este atat primul cat si ultimul
        first = nod;
        last = nod;
        first -> SetNext();     ///singurul nod din lista => are atat anterior cat si next nullptr
        first -> SetAnte();
        last -> SetNext();
        last -> SetAnte();
    }
    else
    {
        Nod_dublu* iterator = first;
        iterator -> SetAnte(nod);
        nod -> SetNext(iterator);
        first = nod;
    }
    size++;
}

void Lista::AddToEnd(int info)
{
    Nod_dublu* nod = new Nod_dublu;
    nod -> SetInfo(info);
    if(GetLast() == nullptr)
    {
        first = nod;
        last = nod;
        first -> SetNext();
        first -> SetAnte();
        last -> SetNext();
        last -> SetAnte();
    }
    else
    {
        Nod_dublu* iterator = last;
        iterator -> SetNext(nod);
        nod -> SetAnte(iterator);
        last = nod;
    }
    size++;
}

void Lista::Remove(Nod_dublu* nod)
{
        if(nod != nullptr)
        {
            /// Actualizăm legăturile nodurilor vecine
            if (nod -> GetAnte())
            {
                if(nod == GetFirst())
                    first = nod -> GetNext();
                nod -> GetAnte() -> SetNext(nod -> GetNext());
            }
            else
                first = nod -> GetNext();

            if (nod -> GetNext())
            {
                if(nod == GetLast())
                    last = nod -> GetAnte();
                nod -> GetNext() -> SetAnte(nod -> GetAnte());
            }
            else
                last = nod -> GetAnte();

            nod -> SetNext();
            nod -> SetAnte();
            delete nod; /// Eliberăm memoria alocată pentru nodul șters
            size--;
        }
}

Lista& Lista::operator=(const Lista& lista)
{
    if(this != &lista)
    {
        if(GetFirst())
        {
            Nod_dublu *iterator = first;
            for(int i = 0; i < size; i++)
            {
                Nod_dublu *temp = iterator;
                iterator = iterator -> GetNext();
                delete temp;
            }
        }
        Nod_dublu* temp = lista.first;
        while(temp)
        {
            this -> AddToEnd(temp -> GetInfo());
            temp = temp -> GetNext();
        }
    }
    else
        return *this;
}

istream& operator>>(istream& in, Lista& lista)
{
    if(lista.GetFirst())
    {
        Nod_dublu *iterator = lista.first;
        for(int i = 0; i < lista.size; i++)
        {
            Nod_dublu *temp = iterator;
            iterator = iterator -> GetNext();
            delete temp;
        }
    }
    cout<<"Dimensiunea listei: ";
    lista.size = 0;
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

ostream& operator<<(ostream& out, const Lista& lista)
{
    Nod_dublu* iterator = lista.GetFirst();
    cout<<"Lista are "<<lista.size<<" elemente: ";
    while(iterator)
    {
        out<<iterator -> GetInfo()<<" ";
        iterator = iterator -> GetNext();
    }
    out<<'\n'<<'\n';
    return out;
}

Lista::~Lista()
{
    Nod_dublu *iterator = first;
    for(int i = 0; i < size; i++)
    {
        Nod_dublu *temp = iterator;
        iterator = iterator -> GetNext();
        delete temp;
    }
    size = 0;
}
