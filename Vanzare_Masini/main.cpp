#include <iostream>
#include "Masina.h"
#include "MasinaMini.h"
#include "MasinaMica.h"
#include "MasinaCompacta.h"
#include "MasinaMonovolum.h"
#include "Vanzare.h"
#include "Meniu.h"
#include "Test.h"
using namespace std;

void Citire_N_Obiecte()
{
    int n;
    cout<<"Cate obiecte doriti sa cititi: ";
    cin>>n;

    cout<<"\n-------------Elemente de tip MasinaMini-------------\n";
    MasinaMini M[n+1];
    for(int i = 0; i < n; i++)
        cin>>M[i];
    for(int i = 0; i < n; i++)
        cout<<M[i]<<'\n';
    cout<<'\n';

    cout<<"-------------Elemente de tip MasinaMica-------------\n";
    MasinaMica Mm[n+1];
    for(int i = 0; i < n; i++)
        cin>>Mm[i];
    for(int i = 0; i < n; i++)
        cout<<Mm[i]<<'\n';
    cout<<'\n';

    cout<<"-------------Elemente de tip MasinaCompacta-------------\n";
    MasinaCompacta Mc[n+1];
    for(int i = 0; i < n; i++)
        cin>>Mc[i];
    for(int i = 0; i < n; i++)
        cout<<Mc[i]<<'\n';
    cout<<'\n';

    cout<<"-------------Elemente de tip MasinaMonovolum-------------\n";
    MasinaMonovolum MM[n+1];
    for(int i = 0; i < n; i++)
        cin>>MM[i];
    for(int i = 0; i < n; i++)
        cout<<MM[i]<<'\n';
    cout<<'\n';
}

int main()
{
    //Citire_N_Obiecte();

    Meniu meniu;
    meniu.Start();

    Test T;
    //T.ConstructoriSiDestructori();
    //cout<<'\n';
    //T.CitireSiAfisare();
    //T.UpcastingSiDowncastingPointeri();
    //T.TestareMetode();
    return 0;
}
