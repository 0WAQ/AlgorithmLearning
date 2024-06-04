#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k, len = 0;
    cin >> n >> k;

    vector<vector<vector<ll>>> f(n + 1, vector<vector<ll>>(k + 1, vector<ll>(1 << n)));
    vector<int> cnt(1 << n); // 记录每种状态1的个数
    vector<int> st(1 << n); // 记录所有行内合法的状态

    // 预处理
    for(int s = 0; s < (1 << n); s++) {
        int tot = 0, t = s;
        while(t) {
            if(t & 1) tot++;
            t >>= 1;
        }
        cnt[s] = tot;
        // 即状态s分别向左和右移1位后与s的&必须为0
        if(!(((s << 1) | (s >> 1)) & s))
            st[len++] = s;
    }
    
    /**
     * 状态表示：f[i][j][s1]是第i行，总共放了j个国王，状态为s1时的方案数
     * 属性：数量
     * 初始状态：f[0][0][0] = 1
     * 最终状态：num{f[n][k][所有合法状态]}
     * 额外变量：cnt[]、st[]
     * 状态计算：
     *      s2 是 s1的一个合法状态
     *      f[i][j][s1] = f[i - 1][j - cnt[s1]][s2]
     * 
     * 优化：预处理所有状态1的个数，以及每种状态自身合不合法（即有没有相邻的1）
    */
    
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        // 枚举合法的两个状态
        for(int l = 0; l < len; l++) {
            for(int r = 0; r < len; r++) {
                int s1 = st[l], s2 = st[r];

                // s1与 s2、s2的左右移1位 的&必须非0
                if(!(( s2 | (s2 << 1) | (s2 >> 1) ) & s1)) // 确保行间合法
                    // s2 转移到 s1
                    for(int j = cnt[s1]; j <= k; j++)
                        f[i][j][s1] += f[i - 1][j - cnt[s1]][s2];
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < len; i++)
        ans += f[n][k][st[i]];
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