#ifndef LISTA_CIRCULARA_H
#define LISTA_CIRCULARA_H

#include <iostream>
#include "Lista.h"
using namespace std;

class Lista_circulara: public Lista
{

public:

    ///constructori cu si fara parametrii
    Lista_circulara();
    Lista_circulara(int size);

    ~Lista_circulara();

    Lista_circulara(const Lista_circulara& lista);  ///copy constructorul

    void AddToBegin(int info);
    void AddToEnd(int info);

    Lista_circulara& operator=(const Lista_circulara& lista);
    friend istream& operator>>(istream& in, Lista_circulara& lista);
    friend ostream& operator<<(ostream& out, const Lista_circulara& lista);
};

#endif //LISTA_CIRCULARA_H
