/*
    高精度加法
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
int a[N], b[N], c[N];

int main()
{
    auto read = [](int *x) -> int
    {
        string s;
        cin >> s;
        int len = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            x[len++] = s[i] - '0';
        }
        return len;
    }; 

    int lena = read(a);
    int lenb = read(b);
    int lenc = max(lena, lenb);

    for(int i = 0; i < lenc; i++)
    {
        c[i] += a[i] + b[i];
        if(c[i] >= 10)
        {
            c[i + 1]++;
            c[i] -= 10;
        }
    }

    if(c[lenc])
        lenc++;
    
    for(int i = lenc - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;
    return 0;
}