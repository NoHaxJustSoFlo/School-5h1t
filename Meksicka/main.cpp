#include <iostream>
#include <time.h>

using namespace std;

enum VrstaMesa{ SVINJETINA, JUNETINA, PILETINA, BEZ_MESA };

class Meso
{
private:
    int gramaza;
    VrstaMesa vrstaMesa;
public:
    Meso()
    {
        gramaza = 0;
        vrstaMesa = BEZ_MESA;
    }
    Meso(const Meso& meso)
    {
        gramaza = meso.gramaza;
        vrstaMesa = meso.vrstaMesa;
    }
    bool SetGramaza(int _gramaza)
    {
        if(_gramaza > 0 && _gramaza < 1000)
        {
            gramaza = _gramaza;
            return true;
        }
        return false;
    }
    int GetGramaza()const
    {
        return gramaza;
    }
    void SetVrstaMesa(VrstaMesa _vrstaMesa)
    {
        vrstaMesa = _vrstaMesa;
    }
    VrstaMesa GetVrstaMesa()const
    {
        return vrstaMesa;
    }
};

void IspisiMeso(const Meso& meso)
{
    string vrstaMesa;
    switch(meso.GetVrstaMesa())
    {
    case SVINJETINA:
        vrstaMesa = "Svinjetina";
        break;
    case JUNETINA:
        vrstaMesa = "Junetina";
        break;
    case PILETINA:
        vrstaMesa = "Piletina";
        break;
    case BEZ_MESA:
        cout << "Bez mesa" << endl;
        return;
    }
    cout << vrstaMesa << " " << meso.GetGramaza() << endl;
}

enum VrstaPriloga{ RIZA, POMFRIT, PASULJ, TESTENINA, BEZ_PRILOGA };

class Prilog
{
private:
    VrstaPriloga vrstaPriloga;

public:
    Prilog()
    {
        vrstaPriloga = BEZ_PRILOGA;
    }
    Prilog(const Prilog& prilog)
    {
        vrstaPriloga = prilog.vrstaPriloga;
    }
    void SetPrilog(VrstaPriloga _vrstaPriloga)
    {
        vrstaPriloga = _vrstaPriloga;
    }
    VrstaPriloga GetPrilog()const
    {
        return vrstaPriloga;
    }
};

void IspisiPrilog(const Prilog& prilog)
{
    switch(prilog.GetPrilog())
    {
    case POMFRIT:
        cout << "Pomfrit\n";
        break;
    case RIZA:
        cout << "Riza\n";
        break;
    case PASULJ:
        cout << "Pasulj\n";
        break;
    case TESTENINA:
        cout << "Testenina\n";
        break;
    case BEZ_PRILOGA:
        cout << "Bez priloga\n";
        break;
    }
    cout << endl;
}

enum StanjeObroka{ POCETAK_ODABIRA, ODABRANO_MESO, ODABRAN_PRILOG, SPREMAN, ZAGOREO};

class Obrok
{
private:
    Meso meso;
    Prilog prilog;
    StanjeObroka stanje;
public:
    Obrok() : meso(), prilog()
    {
        stanje = POCETAK_ODABIRA;
    }

    Obrok(VrstaMesa vrstaMesa, int gramaza, VrstaPriloga vrstaPriloga)
    {
        if(!meso.SetGramaza(gramaza))
        {
            meso.SetVrstaMesa(vrstaMesa);
            prilog.SetPrilog(vrstaPriloga);
            stanje = ODABRAN_PRILOG;
        }
        stanje = POCETAK_ODABIRA;
    }

    Meso GetMeso()const
    {
        return meso;
    }

    Prilog GetPrilog()const
    {
        return prilog;
    }

    StanjeObroka GetStanjeObroka()const
    {
        return stanje;
    }

    bool OdaberiMeso(VrstaMesa vrstaMesa, int gramaza)
    {
        if(stanje == POCETAK_ODABIRA)
        {
            if(meso.SetGramaza(gramaza))
            {
                meso.SetVrstaMesa(vrstaMesa);
                stanje = ODABRANO_MESO;
                return true;
            }
        }
        return false;
    }

    bool OdaberiPrilog(VrstaPriloga vrstaPriloga)
    {
        if(stanje == ODABRANO_MESO)
        {
            prilog.SetPrilog(vrstaPriloga);
            stanje = ODABRAN_PRILOG;
            return true;
        }
        return false;
    }

    void Spremi()
    {
        if(stanje == ODABRAN_PRILOG)
        {
            stanje = (rand() % 10 <= 8) ? SPREMAN : ZAGOREO;
        }
    }
};

void IspisiObrok(const Obrok& obrok)
{
    switch(obrok.GetStanjeObroka())
    {
        case POCETAK_ODABIRA:
            cout << "POCETAK_ODABIRA\n";
            break;
        case ODABRANO_MESO:
            cout << "ODABRANO_MESO\n";
            break;
        case ODABRAN_PRILOG:
            cout << "ODABRAN_PRILOG\n";
            break;
        case SPREMAN:
            cout << "SPREMAN\n";
            break;
        case ZAGOREO:
            cout << "ZAGOREO\n";
            break;
    }
    IspisiMeso(obrok.GetMeso());
    IspisiPrilog(obrok.GetPrilog());
}

bool Meni(Obrok& obrok)
{
    cout << "1) Odaberi meso" << endl
         << "2) Odaberi prilog" << endl
         << "3) Spremi" << endl
         << "4) Prikazi obrok" << endl
         << "5) Exit" << endl;
    int izbor;
    do{
        cin >> izbor;
    }while(izbor < 1 || izbor > 5);
    switch(izbor)
    {
    case 1:
        if(obrok.GetStanjeObroka() == POCETAK_ODABIRA)
        {
            cout << "1) Svinjetina\n"
                 << "2) Junetina\n"
                 << "3) Piletina\n"
                 << "4) Bez mesa\n> ";
            do
            {
                cin >> izbor;
            }while(izbor < 1 || izbor > 4);
            int kolicina;
            cout << "Unesi gramazu:\n> ";
            cin >> kolicina;
            if(obrok.OdaberiMeso((VrstaMesa)izbor, kolicina))
            {
                cout << "------------\n"
                     << "   USPESNO  \n"
                     << "------------\n";
            }
            else
            {
                cout << "------------\n"
                     << "  NEUSPESNO \n"
                     << "------------\n";
            }
        }
        else
        {
            cout << "\nVEC ODABRANO!\n";
        }
        break;
    case 2:
        if(obrok.GetStanjeObroka() == ODABRANO_MESO)
        {
            cout << "1) Riza\n"
                 << "2) Pomfrit\n"
                 << "3) Pasulj\n"
                 << "4) Testenina\n"
                 << "5) Bez priloga\n> ";
            do
            {
                cin >> izbor;
            }while(izbor < 1 || izbor > 5);
            obrok.OdaberiPrilog((VrstaPriloga)izbor);
            cout << "------------\n"
                 << "   USPESNO  \n"
                 << "------------\n";
        }
        else
        {
            if(obrok.GetStanjeObroka() == POCETAK_ODABIRA)
            {
                cout << "\nNIJE IZABRANO MESO\n";
            }
            else
            {
                cout << "\nVEC ODABRANO\n";
            }
        }
        break;
    case 3:
        if(obrok.GetStanjeObroka() == ODABRAN_PRILOG)
        {
            obrok.Spremi();
            cout << "\nUSPESNO\n\n";
        }
        else
        {
            cout << "\nNIJE SVE IZABRANO\n";
        }
        break;
    case 4:
        IspisiObrok(obrok);
        break;
    case 5:
        return true;
    }
    return false;
}

int main()
{
    srand(time(NULL));
    Obrok obrok;
    while(!Meni(obrok));
    return 0;
}
