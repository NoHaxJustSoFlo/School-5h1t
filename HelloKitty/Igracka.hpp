#ifndef IGRACKA_HPP_INCLUDED
#define IGRACKA_HPP_INCLUDED

#include "dinstring.hpp"

class Igracka
{
protected:
    DinString naziv;
    DinString opsegGodina;
public:
    DinString GetNaziv(){return naziv;}
    DinString GetOpseg(){return opsegGodina;}

    virtual void Ispisi()=0;
};


#endif // IGRACKA_HPP_INCLUDED
