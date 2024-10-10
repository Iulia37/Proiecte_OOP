#include "Test.h"
using namespace std;

void Test::ConstructoriSiDestructori()
{
    MasinaMini("Mini", "Cooper", 2015, 2700, 2.5);
    MasinaMica("Ford", "Fiesta", 2009, 3000, 3.6);
    MasinaCompacta("Volkswagen", "Golf 5", 2005, 3200, 4);
    MasinaMonovolum(false, "Volkswagen", "Sharan", 2012, 8000, 5);
    ///mesajele din constructori si destructori sunt comentate
}

void Test::CitireSiAfisare()
{
    MasinaMini mini;
    MasinaMica mica;
    MasinaCompacta comp;
    MasinaMonovolum mono;
    cout<<"MINI\n";
    cin>>mini;
    cout<<mini;
    cout<<"MICA\n";
    cin>>mica;
    cout<<mica;
    cout<<"COMPACTA\n";
    cin>>comp;
    cout<<comp;
    cout<<"MONOVOLUM\n";
    cin>>mono;
    cout<<mono;
}

void Test::UpcastingSiDowncastingPointeri()
{
    ///upcasting
    Masina* mini = new MasinaMini("Mini", "Cooper", 2015, 2700, 2.5);
    Masina* mica = new MasinaMica("Ford", "Fiesta", 2009, 3000, 3.6);
    Masina* comp = new MasinaCompacta("Volkswagen", "Golf 5", 2005, 3200, 4);
    Masina* mono = new MasinaMonovolum(false, "Volkswagen", "Sharan", 2012, 8000, 5);

    mini -> Afisare();
    mica -> Afisare();
    comp -> Afisare();
    mono -> Afisare();

    ///downcasting
    MasinaMini* masina_mini = dynamic_cast<MasinaMini*>(mini);
    cout<<*masina_mini;

    delete mini;
    delete mica;
    delete comp;
    delete mono;
}

void Test::TestareMetode()
{
    MasinaMonovolum mono(false, "Volkswagen", "Sharan", 2012, 8000, 5);
    ///testare getteri
    cout<<mono.GetMarca()<<" "<<mono.GetModel()<<" "<<mono.GetAnFabricatie()
        <<" "<<mono.GetPret()<<" "<<mono.GetLungime()<<'\n';

    ///testare setteri
    mono.SetPret(7500);

    ///calcularea pretului final
    cout<<"Calcularea pretului final:\n";
    cout<<mono.CalcularePret()<<'\n';
}

