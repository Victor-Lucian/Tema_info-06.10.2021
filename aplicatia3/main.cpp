#include <iostream>
#include <fstream>

using namespace std;

/**
    Sa se verifice daca in triunghiul de deasupra diagonalei secundare exista cel putin un numar palindrom.
*/

/**
    Exemplu:
    4
    12 7 1 8
    22 9 11 2
    15 4 5 13
    3 18 10 6

    22 = 22 => Da
*/

void citire (int a[105][105], int &n)
{
    ifstream fin ("matrice.in");
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> a[i][j];
}

int oglindit (int x)
{
    int aux = x;
    int ogl = 0;
    if (x > 9)
        while (aux)
        {
            ogl = ogl * 10 + aux % 10;
            aux /= 10;
        }
    return ogl;
}

int numarare_palindrom (int a[105][105], int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (oglindit(a[i][j]) == a[i][j])
                cnt++;
    return cnt;
}

void afisare (int a[105][105], int &n)
{
    ofstream fout ("matrice.out");
    if (numarare_palindrom(a, n) >= 1)
        fout << "Da";
    else
        fout << "NU";
}

int main()
{
    int n, a[105][105];
    citire(a, n);
    numarare_palindrom(a, n);
    afisare(a, n);
    return 0;
}
