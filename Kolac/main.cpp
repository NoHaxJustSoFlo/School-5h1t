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
    string GetTip() const
    {
        return tip == COKOLADNI ? "COKOLADNI" : "COKOLADNI SA SLAGOM";
    }
};

void IspisiPreliv(const Preliv& preliv)
{
    cout << "------------------------" << endl
         << "Preliv: " << preliv.GetTip() << endl
         << "------------------------"; << endl;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
