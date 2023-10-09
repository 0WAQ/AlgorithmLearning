#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e6 + 5;
int a[N];

int main()
{
    int n, mx = -1;
    LL m;
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {    
        cin >> a[i];
        mx = max(a[i], mx);
    }
    
    auto check = [=](int mid) -> bool
    {
        LL s = 0;
        for(int i = 1; i <= n; i++)
           s += ((a[i] > mid) ? (a[i] - mid) : 0);

        return s >= m;
    };

    int l = 1, r = mx, ans = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}