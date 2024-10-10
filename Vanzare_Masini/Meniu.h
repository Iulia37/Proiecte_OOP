#ifndef MENIU_H
#define MENIU_H

#include <iostream>
#include <string>
#include "Vanzare.h"
#include "Masina.h"
#include "MasinaMini.h"
#include "MasinaMica.h"
#include "MasinaCompacta.h"
#include "MasinaMonovolum.h"
using namespace std;

class Meniu
{
    Vanzare<Masina>vanzare;
public:
    void Start();
};

#endif // MENIU_H
