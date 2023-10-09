#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int a, s[N];
long long p, q;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if(i == 1)
            continue;
        a = s[i] - s[i - 1];
        if(a > 0)
            p += a;
        else
            q -= a;
    }
    long long ans1 = max(p, q);
    long long ans2 = abs(p - q) + 1;
    cout << ans1 << '\n' << ans2 << endl;
    
    return 0;
}