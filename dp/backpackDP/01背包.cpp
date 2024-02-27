// p1048-模板题
#include <iostream>
using namespace std;

const int N = 110, M = 1010;
int dp[M], w[N], v[N];
int n, m;

/**
 * 状态表示：dp[i][j]：从前i个物品中任选，容量为j的最大价值
 * 最终状态：dp[n][m]
 * 初始状态：一个物品都不选：dp[0][j] = 0；背包容量为0：dp[i][0] = 0
 * 状态转移：考虑第i个物品选不选（能选就选）
 *          1.若选，dp[i][j] = dp[i - 1][j - w[i]] + v[i]
 *          2.若不选，dp[i][j] = dp[i - 1][j]
 *          3.求最大价值max
 * 状态方程：j >= w[i]，dp[j] = max(dp[j], dp[j - w[i]] + v[i]); // 滚动数组优化
*/

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[m] << endl;
    return 0;
}