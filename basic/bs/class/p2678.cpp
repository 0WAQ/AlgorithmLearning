#include <iostream>
using namespace std;

const int N = 5e4 + 5;
int d[N];

int main()
{
    int L, n, m;
    cin >> L >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    d[n + 1] = L;

    auto check = [=](int mid) -> bool
    {
        int now = 0, next = 0, x = 0;
        while(next < n + 1)
        {
            next++;
            if(d[next] - d[now] < mid)     
                x++;
            else
                now = next;
        }

        return x > m;
    };

    int l = 1, r = L, ans = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            r = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}