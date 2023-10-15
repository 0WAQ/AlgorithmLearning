#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N], c[N];

int main()
{
    auto read = [](int *x, string s) -> int
    {
        int len = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            x[len++] = s[i] - '0';
        }
        return len;
    };

    string s1, s2;
    cin >> s1 >> s2;
    
    if(s1 < s2)
    {
        swap(s1, s2);
        cout << '-';
    }

    int lena = read(a, s1);
    int lenb = read(b, s2);
    int lenc = max(lena, lenb);


    for(int i = 0; i < lenc; i++)
    {
        c[i] += a[i] - b[i];
        if(c[i] < 0)
        {
            c[i] += 10;
            c[i + 1]--;
        }
    }

    do
        lenc--;
    while(!c[lenc] && lenc > 0);

    for(int i = lenc; i >= 0; i--)
        cout << c[i];
    cout << endl;

    return 0;
}