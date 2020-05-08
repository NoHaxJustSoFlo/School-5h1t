#ifndef PUTOVANJE_HPP_INCLUDED
#define PUTOVANJE_HPP_INCLUDED

class Putovanje
{
private:
    DinString nazivPutovanja;
    int maxCena;
    List<AvionskaKarta> karte;
public:
    Putovanje(){nazivPutovanja = "Express putovanje";maxCena = 10000;}
    Putovanje(DinString n,int max){nazivPutovanja = n; maxCena = max;}

    DinString GetNazivPutovanja(){return nazivPutovanja;}
    int GetMaxCena(){return maxCena;}

    bool DodajAvionskuKartu(AvionskaKarta &a)
    {
        AvionskaKarta avionskaKarta;
        for(int i = 0; i <= karte.size(); i++)
        {
            karte.read(i, avionskaKarta);
            if(avionskaKarta.GetId() == a.GetId())
            {
                return false;
            }
        }
        if(avionskaKarta.GetMestoDolaska() != a.GetMestoPolaska())
        {
            return false;
        }
        if(a.GetCena() > maxCena)
        {
            return false;
        }
        return karte.add(karte.size()+1,a);
    }
    bool IzbaciKartu(int id)
    {
        AvionskaKarta karta;
        int i;
        for(i = 0;i <= karte.size();i++)
        {
            karte.read(i,karta);
            if(karta.GetId() == id)
            {
                karte.remove(i);
                return true;
            }
            return false;
        }
    }
    void IspisPutovanja()
    {
        cout<<"Maksimalna cena puta: "<<GetMaxCena()<<endl;
        cout<<"Naziv putovanja: "<<GetNazivPutovanja()<<endl;
    }
};

#endif // PUTOVANJE_HPP_INCLUDED
