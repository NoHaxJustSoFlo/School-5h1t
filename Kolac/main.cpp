#include <iostream>

using namespace std;

enum TipPreliva{ COKOLADNI, COKOLADNI_SA_SLAGOM };

class Preliv
{
private:
    TipPreliva tip;
public:
    Preliv(TipPreliva _tip = COKOLADNI)
    {
        tip = _tip;
    }
    bool DodajSlag()
    {
        if(tip == COKOLADNI)
        {
            tip = COKOLADNI_SA_SLAGOM;
            return true;
        }
        return false;
    }
    bool UkloniSlag()
    {
        if(tip == COKOLADNI_SA_SLAGOM)
        {
            tip = COKOLADNI;
            return true;
        }
        return false;
    }
    TipPreliva GetTip() const
    {
        return tip;
    }
};

void IspisiPreliv(const Preliv& preliv)
{
    cout << "------------------------" << endl
         << "Preliv: " << ((preliv.GetTip() == COKOLADNI) ? "COKOLADNI" : "COKOLADNI_SA_SLAGOM") << endl
         << "------------------------" << endl;
}

enum KolacStanje{ U_PRIPREMI, PECE_SE, ZAGOREO, PRIPREMLJEN };

class Kolac
{
private:
    KolacStanje stanje;
    int temperatura;
    Preliv preliv;
public:
    Kolac() : preliv()
    {
        temperatura = 20;
        stanje = U_PRIPREMI;
    }
    Kolac(const Kolac& kolac) : preliv(kolac.GetPreliv().GetTip())
    {
        temperatura = kolac.temperatura;
        stanje = kolac.stanje;
    }
    int GetTemperatura()const
    {
        return temperatura;
    }
    KolacStanje GetStanje()const
    {
        return stanje;
    }
    Preliv GetPreliv()const
    {
        return preliv;
    }
    bool StaviDaSePece()
    {
        if(preliv.GetTip() == COKOLADNI)
        {
            stanje = PECE_SE;
            PovecajTemperaturu();
            return true;
        }
        return false;
    }
    bool IspeciKolac()
    {
        if(stanje == PECE_SE)
        {
            stanje = U_PRIPREMI;
            temperatura = 20;
            return true;
        }
        return false;
    }
    bool ZavrsiKolac()
    {
        if(stanje == U_PRIPREMI)
        {
            stanje = PRIPREMLJEN;
            return true;
        }
        return false;
    }
    bool PovecajTemperaturu()
    {
        if(stanje == PECE_SE)
        {
            temperatura += 20;
            if(temperatura > 100)
            {
                stanje = ZAGOREO;
                temperatura = 20;
                return false;
            }
            return true;
        }
        return false;
    }
    bool SmanjiTemperaturu()
    {
        if(stanje == PECE_SE)
        {
            if(temperatura - 20 >= 40)
            {
                temperatura -= 20;
                return true;
            }
        }
        return false;
    }
    bool DodajSlag()
    {
        if(stanje == U_PRIPREMI)
        {
            return preliv.DodajSlag();
        }
        return false;
    }
    bool UkloniSlag()
    {
        if(stanje == U_PRIPREMI)
        {
            return preliv.UkloniSlag();
        }
        return false;
    }
};

void IspisiKolac(const Kolac& kolac)
{
    string stanje;
        switch(kolac.GetStanje())
        {
        case U_PRIPREMI:
            stanje = "U_PRIPREMI";
            break;
        case PECE_SE:
            stanje = "PECE_SE";
            break;
        case ZAGOREO:
            stanje = "ZAGOREO";
            break;
        case PRIPREMLJEN:
            stanje = "PRIPREMLJEN";
            break;
        }
    cout << "------------------------" << endl
         << "Stanje: " << stanje << endl
         << "Temperatura: " << kolac.GetTemperatura() << endl
         << "Preliv: " << ((kolac.GetPreliv().GetTip() == COKOLADNI) ? "COKOLADNI" : "COKOLADNI_SA_SLAGOM") << endl
         << "------------------------" << endl;
}

bool Meni(Kolac& kolac)
{
    cout << "1) Stavi da se pece" << endl
         << "2) Ispeci kolac" << endl
         << "3) Zavrsi kolac" << endl
         << "4) Povecaj temperaturu" << endl
         << "5) Smanji temperaturu" << endl
         << "6) Dodaj slag" << endl
         << "7) Ukloni slag" << endl
         << "8) Ispis kolac" << endl
         << "9) Ispis preliv" << endl
         << "10) Exit" << endl
         << "> ";
    int izbor = 0;
    do
    {
        cin >> izbor;
    }while(izbor < 1 || izbor > 10);
    bool uspesno;
    switch(izbor)
    {
    case 1:
        uspesno = kolac.StaviDaSePece();
        break;
    case 2:
        uspesno = kolac.IspeciKolac();
        break;
    case 3:
        uspesno = kolac.ZavrsiKolac();
        break;
    case 4:
        uspesno = kolac.PovecajTemperaturu();
        break;
    case 5:
        uspesno = kolac.SmanjiTemperaturu();
        break;
    case 6:
        uspesno = kolac.DodajSlag();
        break;
    case 7:
        uspesno = kolac.UkloniSlag();
        break;
    case 8:
        IspisiKolac(kolac);
        return false;
    case 9:
        IspisiPreliv(kolac.GetPreliv());
        return false;
    case 10:
        return true;
    }
    cout << "------------------------" << endl
         << (uspesno ? "       USPESNO" : "       NEUSPESNO") << endl
         << "------------------------" << endl;
    return false;
}

int main()
{
    Kolac kolac;
    while(!Meni(kolac));
    return 0;
}
