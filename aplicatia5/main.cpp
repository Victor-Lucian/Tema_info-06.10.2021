#include <iostream>
#include <fstream>

using namespace std;

/**
    Sa se calculeze minimul dintre valorile care incep cu o cifra para
    de pe fiecare coloana situata sub diag principala.
*/

void citire (int a[105][105], int &n)
{
    ifstream fin ("matrice.in");
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        fin >> a[i][j];
}

void afisare (int a[105][105], int &n)
{
    ofstream fout ("matrice.out");

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
