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
    Pravougaonik(const Pravougaonik& pravougaonik)
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

class Kvadrat : public Pravougaonik
{
public:
    Kvadrat() : Pravougaonik(3, 3)
    {

    }
    Kvadrat(int a) : Pravougaonik(a, a)
    {

    }
    Kvadrat(const Kvadrat& kvadrat) : Pravougaonik(kvadrat)
    {

    }
};

class Krug : public Elipsa
{
public:
    Krug() : Elipsa(3, 3)
    {

    }
    Krug(float r) : Elipsa(r, r)
    {

    }
    Krug(const Krug& krug) : Elipsa(krug)
    {

    }
};

class Oblik
{
private:
    Kvadrat kvadrat;
    Krug krug;
public:
    Oblik()
    {

    }
    Oblik(float a) : kvadrat(a), krug(a / 2)
    {

    }
    Oblik(const Oblik& oblik) : kvadrat(oblik.kvadrat), krug(oblik.krug)
    {

    }
    float Obim()
    {
        return krug.Obim() + kvadrat.Obim();
    }
    float Povrsina()
    {
        return kvadrat.Povrsina() - krug.Povrsina();
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
    Oblik o1(2);
    Oblik o2(o1);
    cout << o1.Obim() << " " << o1.Povrsina() << endl;
    cout << o2.Obim() << " " << o2.Povrsina() << endl;
    Kvadrat k1;
    Kvadrat k2(k1);
    Kvadrat k3(3);
    cout << k1.Obim() << " " << k1.Povrsina() << endl;
    cout << k2.Obim() << " " << k2.Povrsina() << endl;
    cout << k3.Obim() << " " << k3.Povrsina() << endl;
    Krug kr1;
    Krug kr2(kr1);
    Krug kr3(3);
    cout << kr1.Obim() << " " << kr1.Povrsina() << endl;
    cout << kr2.Obim() << " " << kr2.Povrsina() << endl;
    cout << kr3.Obim() << " " << kr3.Povrsina() << endl;
}
