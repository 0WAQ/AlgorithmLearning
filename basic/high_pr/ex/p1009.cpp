#include <iostream>
using namespace std;

const int N = 105;
int a[N], s[N];

void sum()
{
    int t = 0;
    for(int i = 0; i < 100; i++)
    {
        s[i] = s[i] + a[i] + t;
        t = s[i] / 10;
        s[i] = s[i] % 10;
    }
}

void mul(int x)
{
    int t = 0;
    for(int i = 0; i < 100; i++)
    {
        a[i] = a[i] * x + t;
        t = a[i] / 10;
        a[i] = a[i] % 10;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;

    a[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        mul(i);
        sum();
    }

    int w = 0;
    for(int i = 100; i >= 0; i--)
        if(s[i])
        {
            w = i;
            break;
        }   
    for(int i = w; i >= 0; i--)
        cout << s[i];
    cout << endl;
    return 0;
}