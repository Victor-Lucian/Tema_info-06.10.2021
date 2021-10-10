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

bool primalitate (int x)
{
    if (x < 2 || (x % 2 == 0 && x > 2))
        return false;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}

void sortare (int x, int n)
{
    int v[105];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (primalitate(x) == true)
            v[cnt++] = x;
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (v[i] < v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void diag_prin (int a[105][105], int n)
{
    for (int i = 0; i < n; i++)
        sortare(a[i][i], n);
}

void afisare (int a[105][105], int &n)
{
    ofstream fout ("matrice.out");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diag_prin(a, n);
            fout << a[i][j] << " ";
        }
        fout << '\n';
    }
}

int main()
{
    int a[105][105], n;
    citire(a, n);
    diag_prin(a, n);
    afisare(a, n);
    return 0;
}
