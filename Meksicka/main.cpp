#include <iostream>

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
        cout << "Pomfrit";
        break;
    case RIZA:
        cout << "Riza";
        break;
    case PASULJ:
        cout << "Pasulj";
        break;
    case TESTENINA:
        cout << "Testenina";
        break;
    case BEZ_PRILOGA:
        cout << "Bez priloga";
        break;
    }
    cout << endl;
}

class Obrok
{

};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
