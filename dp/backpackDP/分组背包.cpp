#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> s(n + 1), f(m + 1);
    vector<vector<int>> w(n + 1, vector<int>(101)),
                        v(n + 1, vector<int>(101));
    
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++)
            cin >> w[i][j] >> v[i][j];
    }

    /**
     * 将每组物品看作一个物品，同01背包
     * 第三层循环，来选取组内的物品
    */

    /**
     * 状态表示：f[j]只从前i组物品中选，且总体积不大于j的总价值
     * 属性：Max
     * 初始状态：无
     * 最终状态：f[m]
     * 状态计算：
     *      不选：f[j] = f[j]
     *      选：遍历组内物品k，当容量足够(j >= w[i][k])，选取max
    */

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 0; j--)
            for(int k = 0; k <= s[i]; k++)
                if(j >= w[i][k]) 
                    f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);

    cout << f[m] << endl;
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