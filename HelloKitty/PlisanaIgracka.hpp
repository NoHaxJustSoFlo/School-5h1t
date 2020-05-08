#ifndef PLISANAIGRACKA_HPP_INCLUDED
#define PLISANAIGRACKA_HPP_INCLUDED

enum Vrsta {Medo,Zeko,Kuca,Maca};
class PlisanaIgracka : public Igracka
{
private:
    Vrsta vrstaPlisane;
public:
    PlisanaIgracka()
    {
        naziv = "Hello Kitty";
        opsegGodina = "2-7";
        vrstaPlisane = Maca;
    }
    PlisanaIgracka(DinString naziv, DinString opsegGodina, Vrsta vrstaPlisane)
    {
        this->naziv = naziv;
        this->opsegGodina = opsegGodina;
        this->vrstaPlisane = vrstaPlisane;
    }
    PlisanaIgracka(const PlisanaIgracka &plisanaIgracka)
    {
        naziv = plisanaIgracka.naziv;
        opsegGodina = plisanaIgracka.opsegGodina;
        vrstaPlisane = plisanaIgracka.vrstaPlisane;
    }

    string GetVrsta()
    {
        switch(vrstaPlisane)
        {
        case Medo:
            return "Medo";
            break;
        case Zeko:
            return "Zeko";
            break;
        case Kuca:
            return "Kuca";
            break;
        case Maca:
            return "Maca";
            break;
        default:
            return "Nema vrste";
            break;
        }
    }
    void Ispisi()
    {
        cout<<"Naziv: "<<GetNaziv()<<endl;
        cout<<"Vrsta: "<<GetVrsta()<<endl;
        cout<<"Opseg godina: "<<GetOpseg()<<endl;
    }

};

#endif // PLISANAIGRACKA_HPP_INCLUDED
