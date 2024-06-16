// 参考：https://www.bilibili.com/video/BV14m42177cJ/?vd_source=140a9a07403bc18393f243c29b890edf
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * 树形dp：换根dp
 * 状态表示：dp[i]表示点i到其它所有点的 距离*点权 之和
 * 初始状态：dp[1](可以以任意点1<=i<=n为初始状态)，需要在dfs中计算得出
 * 最终状态：min({dp[i]})
 * 状态转移方程：dp[i] = dp[u] + tot - 2 * sum[i]
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    for(int i = 1; i < n; i++) // n - 1 条边
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    ll tot = 0; // 所有点的权值和
    vector<ll> a(n + 1), dp(n + 1), sum(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    // 计算tot、sum、初始状态dp[1]
    auto dfs = [&](auto& dfs, int u, int fa, ll dep) -> void {
        tot += a[u];  // 可以在输入时处理
        dp[1] += a[u] * dep; // 初始状态：∑(a[u] * dep[u])，1 <= u <= n
        
        sum[u] = a[u];  // sum[u]：以u为根时的树的权值和
        for(auto& i : e[u]) {
            if(i == fa) continue;  // 建的图为双向图，这个条件是为了防止向回走 
            dfs(dfs, i, u, dep + 1);  // 向下递归，计算所有sum
            sum[u] += sum[i];   // 子节点的权值，归的过程中算
        } 
    };

    // 状态转移
    auto ddfs = [&](auto& ddfs, int u, int fa) -> void {
        for(auto& i : e[u]) {
            if(i == fa)    continue;   // 同上
            dp[i] = dp[u] + tot - 2 * sum[i];
            ddfs(ddfs, i, u);
        }
    };

    dfs(dfs, 1, 0, 0);
    ddfs(ddfs, 1, 0);

    ll mn = dp[1];
    for(int i = 1; i <= n; i++)
        mn = min(mn, dp[i]);
    cout << mn << endl;

    return 0;
}