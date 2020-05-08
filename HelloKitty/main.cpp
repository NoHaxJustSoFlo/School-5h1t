#include <iostream>

#include "Lista.hpp"
#include "Igracka.hpp"
#include "Plisanaigracka.hpp"
#include "Autic.hpp"
#include "Igraonica.hpp"

using namespace std;


int main()
{
    PlisanaIgracka P;
    PlisanaIgracka P1("Teddy","2-8",Kuca);
    PlisanaIgracka P2(P);
    P.Ispisi();
    P1.Ispisi();
    P2.Ispisi();

    Autic A;
    Autic A1("Mercedes","5-10",true);
    Autic A2(A);
    A.Ispisi();
    A1.Ispisi();
    A2.Ispisi();

    Igracka *igracka1 = &P1;
    Igracka *igracka2 = &A1;

    Igraonica igraonicica;
    igraonicica.DodajIgracku(igracka1);
    igraonicica.DodajIgracku(igracka2);
    igraonicica.IspisIgracke();

    igraonicica.BaciIgracku(1);
    igraonicica.IspisIgracke();

    cout<<"Trazenje igracke"<<endl;
    if(igraonicica.NadjiIgracku("Teddy")==1)
    {
        cout<<endl;
        cout<<"Nadjeno"<<endl;
    }else
        cout<<endl;
        cout<<"Nema"<<endl;
    return 0;
}
