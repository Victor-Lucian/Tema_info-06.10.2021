#include <iostream>
#include <fstream>

using namespace std;

/**
    Suma valorilor situate in triunghiul de deasupra
    diagonalei principale care au un numar par de divizori primi.
*/


/**
    Exemplu:
n = 4
    12 7 1 8
    20 9 11 2
    15 4 5 13
    3 18 10 6

    7: 1, 7 => DA
    1: 1 => NU
    8: 1, 2, 4, 8  => NU
    11: 1, 11 => DA
    2: 1, 2 => DA
    13: 1, 13 => DA
*/
void citire (int a[105][105], int &n)
{
    ifstream fin ("matrice.in");
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> a[i][j];
}

int numarul_div (int x)
{
    int nr = 1, p;
    for (p = 0; x % 2 == 0; x /= 2, p++);
    if (p > 0)
        nr++;
    for (int d = 3; d * d <= x; d += 2)
    {
        for (p = 0; x % d == 0; x /= d, p++);
        if (p > 0)
            nr++;
    }
    if (x != 1)
        nr++;
    return nr;
}

int sum (int a[105][105], int n)
{
    int suma = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numarul_div(a[i][j]) % 2 == 0)
                suma += a[i][j];
        }
    }
    return suma;
}

void afisare (int a[105][105], int &n)
{
    ofstream fout ("matrice.out");
    fout << sum(a, n);
}

int main()
{
    int a[105][105], n;
    citire (a, n);
    sum(a, n);
    afisare(a, n);
    return 0;
}
