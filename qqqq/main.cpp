#include <iostream>

using namespace std;

int main()
{
    int broj = 0;
    for(int i = 1; i <= 2239; i++)
    {
        if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
        {
            broj++;
        }
    }
    cout << broj;
}
