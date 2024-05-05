// [NOIP2012 普及组] 摆花
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e6 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    /**
     * 类似于 多重背包 和 AcWing900整数划分 的
     * 
     * 状态表示：f[i][j]是前i个物品，容量恰好为j的方案数
     * 属性：数量
     * 初始状态：f[0][0] = 1
     * 最终状态：f[n][m]
     * 状态计算：类似于多重背包，第三维枚举物品的数量
    */

    vector<vector<int>> f(n + 1, vector<int>(m + 1));

    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for(int k = 0; k <= a[i] && k <= j; k++)
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
    cout << f[n][m] << endl;
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