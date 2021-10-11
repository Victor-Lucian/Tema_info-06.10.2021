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

void sortare (int a[105][105], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (primalitate(a[i][i]) == true)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (primalitate(a[j][j]) == true)
                {
                    if (a[i][i] > a[j][j])
                    {
                        int aux = a[i][i];
                        a[i][i] = a[j][j];
                        a[j][j] = aux;
                    }
                }
            }
        }
    }
}

void afisare (int a[105][105], int &n)
{
    ofstream fout ("matrice.out");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sortare(a, n);
            fout << a[i][j] << " ";
        }
        fout << '\n';
    }
}

int main()
{
    int a[105][105], n;
    citire(a, n);
    sortare(a, n);
    afisare(a, n);
    return 0;
}
