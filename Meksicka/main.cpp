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
        vrstaMesa = "Bez mesa";
    }
    cout << vrstaMesa << " " << meso.GetGramaza() << endl;
}

class Prilog
{

};

class Obrok
{

};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
