#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<ll> a(k + 1);
    for(int i = 1; i <= k; i++) cin >> a[i];

    ll ans = 0;
    if(k & 1)
    {   
        ll s = 0;
        // 相当于把1删了
        for(int i = k; i >= 2; i -= 2)
            s += a[i] - a[i - 1];

        ans = s;
        // 相当于把 i + 1 删了
        for(int i = 1; i < k; i += 2)
        {
            s -= a[i + 2] - a[i + 1];
            s += a[i + 1] - a[i];
            ans = min(ans, s);
        }
    }
    else
        for(int i = 2; i <= k; i += 2)
            ans += a[i] - a[i - 1];
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}