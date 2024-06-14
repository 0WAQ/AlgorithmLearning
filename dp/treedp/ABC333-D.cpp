#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    vector<int> out(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        // u与v不确定父子
        g[u].push_back(v);
        g[v].push_back(u);
    }

    /**
     * 建立一棵以1为根的树, 要使删掉1的代价最小, 那么只需保留1的一棵边权最大子树即可, 树形dp
     * 
     * 状态表示: f[i]是以i为根的子树的边权之和(边权为1)
     * 属性: max
     * 初始状态: f[u] = 1, 为u与子树的边
     * 最终状态: (n - 1) - (max{f[i]} + 1) = n - max{f[i]}
     * 状态计算: f[u] += f[v]
     */

    vector<int> f(n + 1);

    auto dfs = [&](auto& dfs, int u, int fa) -> void
    {
        // 初始状态
        f[u] = 1;

        // 遍历u的所有子树
        for(auto& v : g[u]) 
            // 双向边, 防止返回父节点
            if(v != fa) 
            {
                dfs(dfs, v, u);
                f[u] += f[v];
            }
    };

    dfs(dfs, 1, 0);

    int ans = 0;
    for(auto& i : g[1])
        ans = max(ans, f[i]);
    cout << n - ans << endl;
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