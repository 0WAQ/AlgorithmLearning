#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, k, v, m;
    double z, r;
    cin >> n >> z >> r;

    vector<int> a(n), x(n);
    vector<double> ans(n, 0);

    a[0] = -1;
    for(int i = 0; i < n; i++) {
        cin >> k;
        if(k == 0) cin >> m, x[i] = m;
        while(k--) cin >> v, a[v] = i;
    }

    ans[0] = z;
    for(int i = 1; i < n; i++) {
        auto dfs = [&](auto& dfs, int x) -> void {
            if(x == 0 || ans[x]) return;    // dfs优化：剪枝
            dfs(dfs, a[x]); // 本行及以上都是递
            ans[x] = ans[a[x]] * (100 - r) * 0.01;  // 归
        };

        dfs(dfs, i);
    }

    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += (x[i] ? ans[i] * x[i] : 0 );

    cout << (int)sum << '\n';
    return 0;
}