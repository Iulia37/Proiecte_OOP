#include "Meniu.h"
#include "Except.h"
#include<limits>
using namespace std;

void Meniu::Start()
{
    bool ok = 1;
    while(ok)
    {
        cout<<"\n1.Adauga o masina in stoc"
            <<"\n2.Vinde o masina din stoc"
            <<"\n3.Afiseaza masinile din stoc"
            <<"\n4.Afiseaza masinile vandute"
            <<"\n5.Cate masini sunt in stoc"
            <<"\n6.Cate masini s-au vandut"
            <<"\n7.Stop\n";
        int optiune;
        cin>>optiune;
        if(optiune == 1)
        {
            cout<<"Ce tip de masina doresti sa adaugi?\n"
                <<"Mini, Mica, Compacta sau Monovolum?\n";
            string masina;
            cin>>masina;
            if(masina == "Mini")
            {
                Masina* mini = new MasinaMini;
                try
                {
                    cin>>*mini;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw except;
                    }

                }catch(const Except& e) { cout<<e.InputException()<<'\n'; }
                vanzare.AddStoc(mini);
            }
            else
                if(masina == "Mica")
                {
                    Masina* mica = new MasinaMica;
                    try
                    {
                        cin>>*mica;
                        if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw except;
                        }

                    }catch(const Except& e) { cout<<e.InputException()<<'\n'; }
                    vanzare.AddStoc(mica);
                }
                else
                    if(masina == "Compacta")
                    {
                        Masina* compacta = new MasinaCompacta;
                        try
                        {
                            cin>>*compacta;
                            if(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw except;
                            }

                        }catch(const Except& e) { cout<<e.InputException()<<'\n'; }
                        vanzare.AddStoc(compacta);
                    }
                    else
                    {
                        MasinaMonovolum* monovolum = new MasinaMonovolum;
                        try
                        {
                            cin>>*monovolum;
                            if(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw except;
                            }

                        }catch(const Except& e) { cout<<e.InputException()<<'\n'; }
                        vanzare.AddStoc(monovolum);
                    }
        }
        else
            if(optiune == 2)
            {
                cout<<"ID-ul masinii pe care doriti sa o vindeti: ";
                int id;
                cin>>id;
                bool vanduta = 0;
                for(auto& masina:vanzare.GetMasiniStoc())
                {
                    if(id == masina.first -> GetID())
                    {
                        vanzare-=masina.first;
                        vanduta = 1;
                        break;
                    }
                }
                if(vanduta == 0)
                    cout<<"ID invalid, masina nu se afla in stoc\n";
            }
            else
                if(optiune == 3)
                {
                    if(vanzare.GetNrStoc() == 0)
                        cout<<"Nu exista nicio masina in stoc\n";
                    else
                        vanzare.AfisareStoc();
                }
                else
                    if(optiune == 4)
                    {
                        if(vanzare.GetNrVandute() == 0)
                            cout<<"Nu a fost vanduta nicio masina\n";
                        else
                            vanzare.AfisareVanzari();
                    }
                    else
                        if(optiune == 5)
                        {
                            cout<<"La momentul actual, in stoc se afla "<<vanzare.GetNrStoc()<<" masini\n";
                        }
                        else
                            if(optiune == 6)
                            {
                                cout<<"Au fost vandute "<<vanzare.GetNrVandute()<<" masini\n";
                            }
                            else
                                ok = 0;
    }
}
