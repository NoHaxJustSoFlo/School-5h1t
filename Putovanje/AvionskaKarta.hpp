#ifndef AVIONSKAKARTA_HPP_INCLUDED
#define AVIONSKAKARTA_HPP_INCLUDED

#include "karta.hpp"

class AvionskaKarta : public Karta
{
public:
    bool JeftinaKarta()
    {
        if(GetCena()/GetDuzina() < 1)
        {
            return true;
        }else
            return false;
    }

    void Ispisi()
    {
        cout<<"Mesto polaska: "<<GetMestoPolaska()<<endl;
        cout<<"Mesto dolaska: "<<GetMestoDolaska()<<endl;
        cout<<"Duzina puta: "<<GetDuzina()<<endl;
        cout<<"Cena karte: "<<GetCena()<<endl;
        cout<<"ID: "<<GetId()<<endl;
        if(JeftinaKarta() == 1)
        {
            cout<<"Jeftina karta."<<endl;
        }else
            cout<<"Skupa karta."<<endl;
    }
};
#endif // AVIONSKAKARTA_HPP_INCLUDED
