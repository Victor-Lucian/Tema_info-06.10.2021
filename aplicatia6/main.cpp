#include <iostream>
#include <fstream>

using namespace std;

int a[105][105], n;

void citire (int a[105][105], int &n)
{
    ifstream fin ("matrice.in");
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> a[i][j];
}

int nr_cif (int x)
{
    int nr = 0;
    int aux = x;
    do
    {
        nr++;
        aux /= 10;
    }
    while (aux);
    return nr % 2 == 0;
}

int linie (int l)
{

    for (int j = n - l; j < n; j++)
    {
        if (!nr_cif(a[l][j]))
            return 0;
    }
    return 1;
}

void afisare (int a[105][105], int &n)
{
    ofstream fout ("matrice.out");
    int ok = 0;
    for (int i = 0; i < n; i++)
        if (linie(i))
        {
            fout << i << " ";
            ok = 1;
        }
    if (!ok)
        fout << "NU EXISTA LINII";
}

int main()
{
    citire(a, n);
    afisare(a, n);
    return 0;
}
