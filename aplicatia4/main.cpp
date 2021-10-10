#include <iostream>
#include <fstream>

using namespace std;

/**
    Maximul dintre elementele care au suma divizorilor para
    si sunt situate in triunghiul de sub diagonala secundara.
*/

/**
    Exemplu:
    4
    12 7 1 8
    22 9 11 2
    15 4 5 13
    3 18 10 6

    2: 1 -> 1 => NU
    5: 1, 5 -> 6 => Da
    13: 1, 13 -> 14 => Da
    18: 1, 2, 3, 6, 9, 18 -> 39 => NU
    10: 1, 2, 5, 10 -> 18 => Da
    6: 1, 2, 3, 6 -> 12 => Da
*/

void citire (int a[105][105], int &n)
{
    ifstream fin ("matrice.in");
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> a[i][j];
}

int suma_div (int x)
{
    int sum = 0;
    int d = 1;
    for (d = 1; d * d < x; d++)
        if (x % d == 0)
            sum = sum + d + x / d;
    if (d * d == x)
        sum += d;
    return sum;
}

int maxim (int a[105][105], int n)
{
    int cnt = 0;
    int v[n + 1];
    for (int i = 1; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            if (suma_div(a[i][j]) % 2 == 0)
                v[cnt++] = a[i][j];
        }
    }
    int vmax = -10000;
    for (int i = 0; i < cnt; i++)
        if (v[i] > vmax)
            vmax = v[i];
    return vmax;
}

void afisare (int a[105][105], int &n)
{
    ofstream fout ("matrice.out");
    fout << maxim (a, n);
}

int main()
{
    int a[105][105], n;
    citire (a, n);
    maxim (a, n);
    afisare (a, n);
    return 0;
}
