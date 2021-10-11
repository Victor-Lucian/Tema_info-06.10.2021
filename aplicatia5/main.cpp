#include <iostream>
#include <fstream>

///5. Sa se calculeze minimul dintre valorile care incep cu o cifra para de pe fiecare coloana situata sub diag
///principala.

using namespace std;

int a[105][105], n;

void citire()
{
    ifstream fin ("matrice.in");
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> a[i][j];
}
int PrimaCifra (int n)
{
    while(n > 9)
        n /= 10;
    return n;
}
int VerifPrimaCifPara(int n)
{
    if(PrimaCifra(n) % 2 == 0)
        return 1;
    return 0;
}
int minimul(int c)
{
    int mini = 200000000;
    for(int i = c + 1; i < n; i++)
        if(VerifPrimaCifPara(a[i][c]) == 1 && a[i][c] < mini)
            mini = a[i][c];
    return mini;
}
void afisare()
{
    for(int j = 0; j < n - 1; j++)
    {
        int v = minimul(j);
        if(v == 200000000)
            cout << "nu exista";
        else
            cout << v;
        cout << endl;
    }
}
int main()
{
    citire();
    afisare();
    return 0;
}
