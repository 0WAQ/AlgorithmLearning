#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int h[N], w[N];
int n, k;

int main()
{
    int mx = -1;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
        mx = max(max(h[i], w[i]), mx);
    }
    
    auto check = [=](int mid)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += (h[i] / mid) * (w[i] / mid);
        return cnt >= k;
    };

    int l = 1, r = mx, ans = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) // cnt>=k，切多了，边长小了
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