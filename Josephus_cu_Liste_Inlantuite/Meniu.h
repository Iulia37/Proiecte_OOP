#ifndef MENIU_H
#define MENIU_H

#include<iostream>
#include<string>
#include<vector>
#include "Nod.h"
#include "Nod_dublu.h"
#include "Lista.h"
#include "Lista_circulara.h"

class Meniu
{
    Lista_circulara lista;

    ///membri statici
    static const string ADD;
    static const string REMOVE;
    static const string DISPLAY;
    static const string JOSEPHUS;
    static const string STOP;
    void DisplayMenuMessage();

public:
    void RunMenu();
    static vector<string> GetAllCommands();
};

#endif //MENIU_H
