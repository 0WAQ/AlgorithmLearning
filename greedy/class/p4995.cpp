#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

using LL = long long;
#define w(x, y) pow(x - y, 2)

const int N = 305;
int n;
LL h[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];

    sort(h + 1, h + n + 1);
    
    LL ans = 0;
    int i = 0, j = n;
    while(i < j)
    {
        ans += w(h[j], h[i]);
        i++;
        ans += w(h[j], h[i]);
        j--;
    }
    cout << ans << endl;
    return 0;
}