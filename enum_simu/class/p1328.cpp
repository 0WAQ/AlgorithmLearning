#include <iostream>
using namespace std;

const int M = 205;
int a[M], b[M];
int n, na, nb;

int h[5][5] = {
    0, 0, 1, 1, 0,
    1, 0, 0, 1, 0,
    0, 1, 0, 0, 1,
    0, 0, 1, 0, 1,
    1, 1, 0, 0, 0,
};

int main()
{
    cin >> n >> na >> nb;
    for(int i = 0; i < na; i++)
        cin >> a[i];
    for(int i = 0; i < nb; i++)
        cin >> b[i];
    
    int cnta = 0, cntb = 0;

    int j = 0, k = 0;
    for(int i = 0; i < n; i++)
    {   
        cnta += h[a[j]][b[k]];
        cntb += h[b[k]][a[j]];
        j = (j + 1) % na;
        k = (k + 1) % nb;
    }
    cout << cnta << ' ' << cntb << endl;
    return 0;
}