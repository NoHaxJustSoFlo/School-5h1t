#ifndef IGRAONICA_HPP_INCLUDED
#define IGRAONICA_HPP_INCLUDED

#include "Lista.hpp"

class Igraonica
{
private:
    List<Igracka*> igracke;
public:
    bool DodajIgracku(Igracka* i)
    {
        if(igracke.add(igracke.size()+1,i))
        {
            return true;
        }
        return false;
    }
    bool BaciIgracku(int baci)
    {
       if(igracke.remove(baci))
       {
           return true;
       }else
            return false;
    }
    bool NadjiIgracku(DinString ime)
    {
        Igracka* igracka;
        for(int i = 1;i <= igracke.size();i++)
        {
            igracke.read(i,igracka);
            if(igracka->GetNaziv() == ime)
            {
                return true;
            }
        }
        return false;
    }
    void IspisIgracke()
    {
        cout << "Broj igracka u igraonici: " << igracke.size() << endl;
        Igracka* igra;
        for(int i = 1; i <= igracke.size(); i++)
        {
            igracke.read(i,igra);
            igra->Ispisi();
        }
    }
};


#endif // IGRAONICA_HPP_INCLUDED
