#include <iostream>
using namespace std;
#define lowbit(x) x&-x

const int N = 2e5 + 5;
long long a[N], s[N], low[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        low[i] = lowbit(a[i]);
        s[i] = s[i - 1] + low[i];
    }

    long long q, j;
    cin >> q;

    long long i = 1;
    while(q--)
    {
        cin >> j;
        for(; i <= n; i++)
            if(s[i] >= j)
            {
                cout << a[i] / low[i] << endl;
                break;
            }
    }
    return 0;
}