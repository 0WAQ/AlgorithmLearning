// 完全二叉树的层序以及后序遍历
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k = 0;
    cin >> n;

    vector<int> a(n + 1), ans(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    // 模拟了二叉树的后序遍历
    auto dfs = [&](auto& dfs, int x) -> void {
        if(x > n) return;

        dfs(dfs, 2 * x);
        dfs(dfs, 2 * x + 1);
        ans[x] = a[++k];
    };

    dfs(dfs, 1);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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