#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), dep(n + 1), ans;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == -1) dep[i] = 1;
    }

    auto dfs = [&](auto& dfs, int x) -> void 
    {
        if(a[x] == -1)  return;
        if(dep[x])  return;
        
        dfs(dfs, a[x]);
        dep[x] = dep[a[x]] + 1;
    };

    int mx = 0;
    for(int i = 1; i <= n; i++) {
        dfs(dfs, i);
        mx = max(mx, dep[i]);
    }

    for(int i = 1; i <= n; i++)
        if(dep[i] == mx)
            ans.push_back(i);

    cout << mx << '\n';
    for(int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ' ';
    cout << ans[ans.size() - 1] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();

    return 0;
}