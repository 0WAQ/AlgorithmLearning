#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    /**
     * 状态表示：dp[i][j]是前i个数字，用了j次操作后得到的最小值
     * 属性：最小值
     * 初始状态：dp[0][j] = 0，当没有数字时，全为0；其它值为最小值
     * 最终状态：dp[n][m]
     * 状态转移：
     *      1. 不对当前元素进行操作：dp[i][j] = dp[i - 1][j] + a[i];
     *      2. 对当前元素进行操作： dp[i][j] = min(dp[i][j], dp[(i - k) - 1][j - k] + mn * (k + 1))
     *         即当前元素的值可以变为，i元素之前经过的前k(1 <= k <= j)次操作的最小值，这个k次操作是不包含i的     
    */
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e18));
    for(int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {   // 总共的操作次数

            // 1. 不对当前元素进行操作
            dp[i][j] = dp[i - 1][j] + a[i];
            
            // 2. 对当前元素进行操作
            ll mn = a[i];
            for(int k = 1; k <= j && i - k - 1 >= 0; k++) {
                mn = min(mn, a[i - k]); // 找最小值
                dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + mn * (k + 1));
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}