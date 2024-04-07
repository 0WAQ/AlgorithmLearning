#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

const int mod = 998244353;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<int> a(m + 1), b(m + 1), s(n + 2);
    for(int i = 1; i <= m; i++) cin >> a[i] >> b[i];

    ll ans = 0;
    auto dfs = [&](auto& dfs, int x) -> void
    {
        if(x > m)
        {
            vector<int> c(n + 2);
            for(int i = 1; i <= n; i++) {
                c[i] = c[i - 1] + s[i];
                if(c[i] < 2)    return;
            }
            ans++;
            ans %= mod;
            return;
        }

        s[a[x]]++;
        s[b[x] + 1]--;
        dfs(dfs, x + 1);    // 选
        s[a[x]]--;
        s[b[x] + 1]++;
        dfs(dfs, x + 1);    // 不选
    };

    dfs(dfs, 1);
    cout << ans << endl;
    return 0;
}