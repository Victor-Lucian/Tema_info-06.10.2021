#include <iostream>
#include <fstream>

using namespace std;

/**
    Numarul valorilor situate in triunghiul
    de sub diagonala principala care au exact k cifre.
*/

/**
    Exemplu:
    4 2
    12 7 1 8
    20 9 11 2
    15 4 5 13
    3 18 10 6

    20 = 2 cifre => Da
    15 = 2 cifre => Da
    4 = 1 cifra => Nu
    3 = 1 cifra => Nu
    18 = 2 cifre => Da
    10 = 2 cifre => Da
*/

void citire (int a[105][105], int &n, int &k)
{
    ifstream fin ("matrice.in");
    fin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> a[i][j];
}

int nr_cif (int x)
{
    int nr = 0;
    do
    {
        nr++;
        x /= 10;
    }
    while (x);
    return nr;
}

int numarare (int a[105][105], int n, int k)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nr_cif(a[i][j]) == k)
                cnt++;
        }
    }
    return cnt;
}

void afisare (int a[105][105], int &n, int &k)
{
    ofstream fout ("matrice.out");
    fout << numarare(a, n, k);
}

int main()
{
    int a[105][105], n, k;
    citire(a, n, k);
    numarare(a, n, k);
    afisare(a, n, k);
    return 0;
}
