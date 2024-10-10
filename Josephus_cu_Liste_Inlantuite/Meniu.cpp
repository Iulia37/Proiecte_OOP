#include <iostream>
#include "Meniu.h"

const string Meniu::ADD = "ADD";
const string Meniu::REMOVE = "REMOVE";
const string Meniu::DISPLAY = "DISPLAY";
const string Meniu::JOSEPHUS = "JOSEPHUS";
const string Meniu::STOP = "STOP";

void Meniu::DisplayMenuMessage()
{

   cout << ADD << " - citeste si adauga un nou nod in lista" << '\n'
        << REMOVE << " - sterge nodul de pe pozitia x" << '\n'
        << DISPLAY << " -afiseaza toate nodurile din lista" << '\n'
        << JOSEPHUS << " -rezolva problema lui Josephus pentru un N dat" << '\n'
        << STOP << " - opreste programul" << '\n'
        << '\n';
}

void Meniu::RunMenu()
{
    DisplayMenuMessage();

    string command;
    cin >> command;

    while(command != "STOP")
    {
        if(command == "ADD")
        {
            cout<<"Unde doriti sa adaugati nodul?"<<'\n'<<"1 - la inceput"<<'\n'<<"0 - la final"<<'\n';
            int unde;
            cin>>unde;
            int val;
            if(unde == 1)
            {
                cout<<"Nodul va fii adaugat la inceputul listei"<<'\n'<<"Ce valoare doriti sa inserati?"<<'\n';
                cin>>val;
                lista.AddToBegin(val);
            }
            else
                if(unde == 0)
                {
                    cout<<"Nodul va fii adaugat la finalul listei"<<'\n'<<"Ce valoare doriti sa inserati?"<<'\n';
                    cin>>val;
                    lista.AddToEnd(val);
                }

        }
        else
            if(command == "REMOVE")
            {
                cout<<"Doriti sa stergeti nodul de pe pozitia: ";
                int x;
                cin>>x;
                if(x > lista.GetSize() || x <= 0)
                    cout<<"Input invalid";
                else
                {
                    Nod_dublu* nod = lista.GetFirst();
                    for(int i = 1; i < x; i++)
                        nod = nod -> GetNext();
                    lista.Remove(nod);
                }
                cout<<'\n'<<'\n';
            }
            else
                if(command == "DISPLAY")
                {
                    if(lista.GetFirst())
                        cout<<lista<<'\n';
                    else
                        cout<<"Momentan lista este vida!"<<'\n';
                    cout<<'\n';
                }
                else
                    if(command == "JOSEPHUS")
                    {
                        cout<<"Doriti sa faceti problema lui Josephus pentru:\n"
                            <<"7 - lista curenta\n"
                            <<"9 - un N dat\n";
                        int care;
                        cin>>care;
                        if(care == 7)
                        {
                            cout<<"Problema lui Josephus pentru lista circulara curenta";
                            Nod_dublu* nod = lista.GetFirst();
                            Nod_dublu* aux = new Nod_dublu;
                            while(lista.GetSize() > 2)
                            {
                                aux = nod -> GetNext();
                                nod = aux -> GetNext();
                                lista.Remove(aux);
                            }
                            lista.Remove(nod -> GetNext());
                            cout<<'\n'<<"Ultimul soldat ramas in viata este "
                                <<lista.GetFirst() -> GetInfo()<<'\n'<<'\n';
                        }
                        if(care == 9)
                        {
                            Lista_circulara L;
                            cout<<"Problema lui Josephus pentru N = ";
                            int n;
                            cin>>n;
                            for(int i = 1; i <= n; i++)
                                L.AddToEnd(i);
                            Nod_dublu* nod2 = L.GetFirst();
                            Nod_dublu* aux2 = new Nod_dublu;
                            while(L.GetSize() > 2)
                            {
                                aux2 = nod2 -> GetNext();
                                nod2 = aux2 -> GetNext();
                                L.Remove(aux2);
                            }
                            L.Remove(nod2 -> GetNext());
                            cout<<'\n'<<"Ultimul soldat ramas in viata este "
                                <<L.GetFirst() -> GetInfo()<<'\n'<<'\n';
                        }
                    }

        DisplayMenuMessage();
        cin >> command;
    }
}
