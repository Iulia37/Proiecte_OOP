#include <iostream>
#include "Nod.h"
#include "Nod_dublu.h"
#include "Lista.h"
#include "Lista_circulara.h"
#include "Meniu.h"

using namespace std;

void Test_n_obiecte()
{
    int n;
    cout<<"n = ";
    cin>>n;

    cout<<"-------------Elemente de tip Nod-------------\n"<<'\n';
    Nod nod[n + 1];
    for(int i = 0; i < n; i++)
        cin>>nod[i];
    cout<<'\n';
    for(int i = 0; i < n; i++)
        cout<<nod[i];
    cout<<'\n';

    cout<<"-------------Elemente de tip Nod_dublu-------------\n"<<'\n';
    Nod_dublu nod2[n + 1];
    for(int i = 0; i < n; i++)
        cin>>nod2[i];
    cout<<'\n';
    for(int i = 0; i < n; i++)
        cout<<nod2[i];
    cout<<'\n';

    cout<<"-------------Elemente de tip Lista-------------\n"<<'\n';
    Lista lista[n + 1];
    for(int i = 0; i < n; i++)
        cin>>lista[i];
    cout<<'\n';
    for(int i = 0; i < n; i++)
        cout<<lista[i];
    cout<<'\n';

    cout<<"-------------Elemente de tip Lista_circulara-------------\n"<<'\n';
    Lista_circulara lista2[n + 1];
    for(int i = 0; i < n; i++)
        cin>>lista2[i];
    cout<<'\n';
    for(int i = 0; i < n; i++)
        cout<<lista2[i];
    cout<<'\n';
}

void Test()
{
    cout<<"-------------Clasa Nod-------------\n"<<'\n';
    Nod nod1, nod2(5), nod3(1, &nod2);
    cout<<"Constructor fara parametrii:\n"<<nod1
        <<"Constructor fara parametrul next:\n"<<nod2
        <<"Constructor  parametrizat:\n"<<nod3;
    nod1.SetNext(&nod2);
    nod1.SetInfo(9);
    cout<<"Primul nod dupa folosirea metodei SetNext si SetInfo:\n"<<nod1;
    Nod nod4(nod2);
    cout<<"Un al 4 lea nod cu copy constructor:\n"<<nod4;
    cout<<"Metodele GetInfo si GetNext pentru nodul 1:\n"<<nod1.GetInfo()<<" "<<nod1.GetNext()<<'\n';

    cout<<'\n';

    cout<<"-------------Clasa Nod_dublu-------------\n"<<'\n';
    Nod_dublu nodd1, nodd2(7), nodd3(13, &nodd2, &nodd1);
    cout<<"Constructor fara parametrii:\n"<<nodd1
        <<"Constructor fara parametrul next si ante:\n"<<nodd2
        <<"Constructor  parametrizat:\n"<<nodd3;
    nodd1.SetNext(&nodd2);
    nodd1.SetAnte(&nodd3);
    nodd1.SetInfo(37);
    cout<<"Primul nod dupa folosirea metodei SetInfo, SetNext si SetAnte:\n"<<nodd1;
    Nod_dublu nodd4(nodd2);
    cout<<"Un al 4 lea nod cu copy constructor:\n"<<nodd4;
    cout<<"Metodele GetInfo, GetNext si GetAnte pentru nodul 1:\n"
        <<nodd1.GetInfo()<<" "<<nodd1.GetNext()<<" "<<nodd1.GetAnte()<<'\n';

    cout<<'\n';

    cout<<"-------------Clasa Lista-------------\n"<<'\n';
    Lista lista1, lista2(7);
    cout<<"Constructor fara parametrii:\n"<<lista1
        <<"Constructor parametrizat:\n"<<lista2;
    Lista lista3(lista2);
    cout<<"O a treia lista cu copy constructor:\n"<<lista3;
    lista1.AddToBegin(17);
    lista1.AddToBegin(37);
    lista1.AddToBegin(3);
    lista1.AddToEnd(19);
    lista1.AddToEnd(14);
    cout<<"Prima lista dupa utilizarea metodelor AddToBegin si AddToEnd:\n"<<lista1;
    Nod_dublu* node = lista1.GetFirst();
    node = node -> GetNext();
    lista1.Remove(node);
    cout<<"Prima lista dupa utilizarea metodei Remove pentru al 2lea nod:\n"<<lista1;
    cout<<"Metodele GetSize, GetFirst si GetLast pentru prima lista:\n"
        <<lista1.GetSize()<<" "<<lista1.GetFirst()<<" "<<lista1.GetLast()<<'\n';

    cout<<'\n';

    cout<<"-------------Clasa Lista_circulara-------------\n"<<'\n';
    Lista_circulara list1, list2(11);
    cout<<"Constructor fara parametrii:\n"<<list1
        <<"Constructor parametrizat:\n"<<list2;
    Lista_circulara list3(list2);
    cout<<"O a treia lista circulara cu copy constructor:\n"<<list3;
    list1.AddToBegin(1);
    list1.AddToBegin(3);
    list1.AddToBegin(32);
    list1.AddToEnd(191);
    list1.AddToEnd(14);
    cout<<"Prima lista circulara dupa utilizarea metodelor AddToBegin si AddToEnd:\n"<<list1;
    Nod_dublu* node2 = list1.GetFirst();
    node2 = node2 -> GetNext();
    list1.Remove(node2);
    cout<<"Prima lista circulara dupa utilizarea metodei Remove pentru al 2lea nod:\n"<<list1;
    cout<<"Metodele GetSize, GetFirst si GetLast pentru prima lista circulara:\n"
        <<list1.GetSize()<<" "<<list1.GetFirst()<<" "<<list1.GetLast()<<'\n';
}

int main()
{
    Meniu M;
    //Test();
    //Test_n_obiecte();
    //M.RunMenu();
    return 0;
}
