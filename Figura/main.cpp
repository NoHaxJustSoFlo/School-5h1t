#include <iostream>
#include <math.h>
#define M_PI 3.14159265358979323846

using namespace std;

class Figura
{
public:
    virtual float Obim() = 0;
    virtual float Povrsina() = 0;
};

class Pravougaonik : public Figura
{
private:
    float x,y;

public:
    Pravougaonik()
    {
        x = 2;
        y = 5;
    }
    Pravougaonik(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    Pravougaonik(Pravougaonik& pravougaonik)
    {
        x = pravougaonik.x;
        y = pravougaonik.y;
    }
    float GetX()const
    {
        return x;
    }
    float GetY()const
    {
        return y;
    }
    float Obim() override
    {
        return 2 * x + 2 * y;
    }
    float Povrsina() override
    {
        return x * y;
    }
};

class Elipsa : public Figura
{
private:
    float x,y;

public:
    Elipsa()
    {
        x = 2;
        y = 5;
    }
    Elipsa(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    Elipsa(const Elipsa& elipsa)
    {
        x = elipsa.x;
        y = elipsa.y;
    }
    float GetX()const
    {
        return x;
    }
    float GetY()const
    {
        return y;
    }
    float Obim() override
    {
        return M_PI * (3 * ( x + y ) - sqrt((3*x + y)*(x+3*y)));
    }
    float Povrsina() override
    {
        return x * y * M_PI;
    }
};

class Oblik
{
private:
    Pravougaonik pravougaonik;
    Elipsa elipsa;
public:
    Oblik()
    {

    }
    Oblik(float a, float b) : pravougaonik(a, b), elipsa(a / 2, b / 2)
    {

    }
    Oblik(const Oblik& oblik) : pravougaonik(oblik.pravougaonik.GetX(), oblik.pravougaonik.GetY()), elipsa(oblik.elipsa.GetX(), oblik.elipsa.GetY())
    {

    }
    float Obim()
    {
        return elipsa.Obim() + pravougaonik.Obim();
    }
    float Povrsina()
    {
        return pravougaonik.Povrsina() - elipsa.Povrsina();
    }
};

class PravilanOblik : public Oblik
{
public:
    PravilanOblik() : Oblik(3, 3)
    {

    }
    PravilanOblik(float a) : Oblik(a, a)
    {

    }
    PravilanOblik(const PravilanOblik& oblik) : Oblik(oblik)
    {

    }
};

int main()
{
    Pravougaonik p1;
    Pravougaonik p2(p1);
    Pravougaonik p3(4, 6);
    cout << p1.Obim() << " " << p1.Povrsina() << endl;
    cout << p2.Obim() << " " << p2.Povrsina() << endl;
    cout << p3.Obim() << " " << p3.Povrsina() << endl;
    Elipsa e1;
    Elipsa e2(e1);
    Elipsa e3(4, 6);
    cout << e1.Obim() << " " << e1.Povrsina() << endl;
    cout << e2.Obim() << " " << e2.Povrsina() << endl;
    cout << e3.Obim() << " " << e3.Povrsina() << endl;
    Oblik o1(2, 4);
    Oblik o2(o1);
    cout << o1.Obim() << " " << o1.Povrsina() << endl;
    cout << o2.Obim() << " " << o2.Povrsina() << endl;
    PravilanOblik po1;
    PravilanOblik po2(3);
    cout << po1.Obim() << " " << po1.Povrsina() << endl;
    cout << po2.Obim() << " " << po2.Povrsina() << endl;

}
