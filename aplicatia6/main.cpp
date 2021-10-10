#include <iostream>
#include <fstream>

using namespace std;

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
    return nr;
}

int ind_linie (int a[105][105], int n)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            if (nr_cif(a[i][j]) % 2 == 0)
                cnt++;
        }
        if (cnt == n)
            return i;
    }

}

void afisare (int a[105][105], int n)
{
    ofstream fout ("matrice.out");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fout << ind_linie(a, n) << " ";
}

int main()
{
    int a[105][105], n;
    citire(a, n);
    ind_linie(a, n);
    afisare(a, n);
    return 0;
}
