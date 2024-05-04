// 没有上司的舞会
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> h(n + 1);
    vector<bool> st(n + 1); // 用来寻找根节点
    vector<vector<int>> g(n + 1), dp(n + 1, vector<int>(2));

    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i < n; i++)
    {
        int l, k;
        cin >> l >> k;
        st[l] = true; // 代表l是子节点
        g[k].push_back(l);
    }

    /**
     * 状态表示：dp[x][1], dp[x][0]分别是以x为根的树中，选与不选x的最大和
     * 属性：max
     * 初始状态：从根开始往下遍历，每个结点的dp[x][1] = h[x], dp[x][0] = 0
     * 最终状态：max(dp[root][1], dp[root][0])
     * 状态计算：遍历每个树的根节点x的子节点y（遍历到y时，应该先向下递归计算以子节点为根的树的答案）
     *            1. 当x选时，y不选
     *                  dp[x][1] += dp[y][0]   
     *            2. 当x不选时，y可选可不选
     *                  dp[x][0] += max(dp[y][1], dp[y][0])
    */

    auto dfs = [&](auto& dfs, int x) -> void
    {
        dp[x][1] = h[x];    // 选x
        dp[x][0] = 0;       // 不选x

        // 枚举x的孩子
        for(const auto& y : g[x])
        {
            dfs(dfs ,y);
            
            dp[x][1] += dp[y][0];
            dp[x][0] += max(dp[y][1], dp[y][0]); // 父节点不去，子节点可以去、也可以不去
        }
    };

    int root;
    // 寻找根节点
    for(int i = 1; i <= n; i++) {
        if(!st[i]) {    // st其实是一个入度数组，根节点的入度为0
            root = i;
            break;
        }
    }

    dfs(dfs, root);
    cout << max(dp[root][1], dp[root][0]) << endl;
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