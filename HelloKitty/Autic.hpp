#ifndef AUTIC_HPP_INCLUDED
#define AUTIC_HPP_INCLUDED

class Autic : public Igracka
{
private:
    bool naStruju;
public:
    Autic()
    {
        naziv = "BMW";
        opsegGodina = "5-15";
        naStruju = true;
    }
    Autic(DinString naziv, DinString opsegGodina, bool naStruju)
    {
        this->naziv = naziv;
        this->opsegGodina = opsegGodina;
        this->naStruju = naStruju;
    }
    Autic(const Autic &autic)
    {
        naziv = autic.naziv;
        opsegGodina = autic.opsegGodina;
        naStruju = autic.naStruju;
    }

    string GetStruja()
    {
        if(naStruju)
        {
            return "Na struju";
        }
        return "Nije na struju";
    }

    void Ispisi()
    {
        cout<<"Naziv: "<<GetNaziv()<<endl;
        cout<<"Struja: "<<GetStruja()<<endl;
        cout<<"Opseg godina: "<<GetOpseg()<<endl;
    }
};

#endif // AUTIC_HPP_INCLUDED
