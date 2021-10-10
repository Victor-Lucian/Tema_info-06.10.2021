#include <iostream>
#include <fstream>

using namespace std;

/**
    Suma valorilor situate in triunghiul de deasupra
    diagonalei principale care au un numar par de divizori primi.
*/


/**
    Exemplu:
    4
    12 7 1 6
    20 9 11 2
    15 4 5 13
    3 18 10 6

    7: 1, 7 => NU
    1: 1 => DA
    6: 1, 2, 3  => DA
    11: 1, 11 => NU
    2: 1, 2 => NU
    13: 1, 13 => NU
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
    int nr = 0, p;
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
