// 思维题
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using LL = long long;

const int N = 1e5 + 5;
int a[N];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);

    int o, i, d, s1 = 0, s2 = 0;
    if(n & 1)
    {
        for(int i = 1; i <= n / 2; i++)
            s1 += a[i];
        for(int i = n; i >= n / 2 + 2; i--)
            s2 += a[i];

        o = i = n / 2;

        // 判断是 i 还是 o 加 c = a[n / 2 + 1]，分别加上 c 判断哪一个差距大
        int c = a[n / 2 + 1];
        if(abs(s1 - s2 + c) > abs(s1 - s2 - c))
            i++, s1 += c;
        else
            o++, s2 += c;
        d = abs(s1 - s2);
    }
    else
    {
        for(int i = 1; i <= n; i++)
            if(i <= n / 2)  s1 += a[i];
            else s2 += a[i];
        o = i = n / 2;
        d = abs(s1 - s2);
    }
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n", o, i, d);
    return 0;
}