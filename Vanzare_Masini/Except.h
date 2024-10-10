#ifndef EXCEPT_H
#define EXCEPT_H

#include<iostream>
#include<exception>
using namespace std;

class Except: public exception
{
public:
    virtual const char* InputException() const throw()
    {
        return "Eroare la citire\n";
    }
}except;

#endif // EXCEPT_H
