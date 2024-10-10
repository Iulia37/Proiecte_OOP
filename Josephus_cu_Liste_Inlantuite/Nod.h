#ifndef NOD_H
#define NOD_H

#include <iostream>
using namespace std;

class Nod
{
protected:
    int info;
    Nod *next;

public:
    Nod();                    ///constructorii cu si fara parametrii
    Nod(int info);            ///initializeaza info cu 0 sau cu o valoare data, respectiv next cu NULL sau un Nod dat
    Nod(int info, Nod* next);

    virtual ~Nod();

    Nod(const Nod &nod);    ///copy constructorul

    ///getteri
    int GetInfo() const { return info; }
    Nod* GetNext() const { return next; }

    ///setteri
    void SetInfo(int info);
    void SetNext(Nod *next = nullptr);

    Nod& operator=(const Nod& nod);
    friend istream& operator>>( istream& in, Nod& nod);
    friend ostream& operator<<( ostream& out, const Nod nod);
};

#endif // NOD_H
