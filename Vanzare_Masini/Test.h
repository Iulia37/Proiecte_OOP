#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Masina.h"
#include "MasinaMini.h"
#include "MasinaMica.h"
#include "MasinaMonovolum.h"
#include "MasinaCompacta.h"
using namespace std;

class Test
{
public:
    void ConstructoriSiDestructori();
    void CitireSiAfisare();
    void UpcastingSiDowncastingPointeri();
    void TestareMetode();
};

#endif // TEST_H
