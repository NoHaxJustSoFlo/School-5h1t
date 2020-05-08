#ifndef KARTA_HPP_INCLUDED
#define KARTA_HPP_INCLUDED
#include "dinstring.hpp"
class Karta
{
private:
    DinString mestoPolaska;
    DinString mestoDolaska;
    float duzinaPutovanja;
    float cenaKarte;
    int idKarte;
public:
    DinString GetMestoPolaska(){return mestoPolaska;}
    DinString GetMestoDolaska(){return mestoDolaska;}
    float GetDuzina(){return duzinaPutovanja;}
    float GetCena(){return cenaKarte;}
    int GetId(){return idKarte;}

    Karta()
    {
        mestoPolaska = "Novi Sad";
        mestoDolaska = "Backa Palanka";
        duzinaPutovanja = 60;
        cenaKarte = 500;
        idKarte = 1234;
    }
    Karta(DinString p,DinString d, float duzina, float c, int i)
    {
        mestoPolaska = p;
        mestoDolaska = d;
        duzinaPutovanja  = duzina;
        cenaKarte = c;
        idKarte = i;
    }
    Karta(const Karta &karta)
    {
        mestoPolaska = karta.mestoPolaska;
        mestoDolaska = karta.mestoDolaska;
        duzinaPutovanja = karta.duzinaPutovanja;
        cenaKarte = karta.cenaKarte;
        idKarte = karta.idKarte;
    }

    virtual bool JeftinaKarta()=0;
};

#endif // KARTA_HPP_INCLUDED
