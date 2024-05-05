#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int m, s, t;
    cin >> m >> s >> t;

    /**
     * 状态定义：dp[i]表示i秒内，走过的最远距离
     * 属性：Max
     * 初始状态：dp[0] = 0;
     * 最终状态：1. dp[t] < M, dp[t]
     *          2. dp[t] >= M, 遍历dp找到第一个大于等于M的时间
     * 状态转移：  
     *          回蓝与步走无法权衡，所以没蓝时先无脑回蓝 
     *              m >= 10：用闪烁dp[i] = dp[i - 1] + 60, m -= 10;
     *              m  < 10：原地回蓝dp[i] = dp[i - 1], m += 4;
     *          然后再迭代一次，取回蓝与步行的最大值
     *              dp[i] = max(dp[i], dp[i - 1] + 17)
     *          
    */
    vector<int> dp(t + 1);

    dp[0] = 0;
    for(int i = 1; i <= t; i++)
    {
        if(m >= 10) {
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }
        else {
            dp[i] = dp[i - 1];
            m += 4;
        }
    }

    for(int i = 1; i <= t; i++) 
    {
        dp[i] = max(dp[i], dp[i - 1] + 17);

        if(dp[i] >= s) {
            cout << "Yes\n" << i << endl;
            return;
        }
    }

    cout << "No\n" << dp[t] << endl;
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
