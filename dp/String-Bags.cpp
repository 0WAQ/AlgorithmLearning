// ABC-344-D
#include <iostream>
#include <cstring>
using namespace std;

/**
 * 状态定义：dp[i][j]: 前i包中匹配了的长度j时的最小花费
 * 初始状态：inf，dp[0][0] = 0;
 * 最终状态：dp[n][t.size()]
 * 状态转移：类似于分组背包问题：每一组里要么只选一个，要么不选
 *          不选：dp[i][j] = dp[i - 1][j]
 *          能选的话(t.substr(j, j + s.size() - 1) == s)： 
 *                  dp[i][j + s.size()] = min({dp[i - 1][j] + 1})
*/

const int N = 110;
int dp[N][N];
string t;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t >> n;

    // 初始状态
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    // 遍历组数
    for(int i = 1; i <= n; i++)
    {
        // 在两个遍历之间输入，不影响结果
        int m;
        cin >> m;
        while(m--)
        {
            string s;
            cin >> s;
            
            // 遍历长度，需要加等于号，因为长度可以是t.size()
            for(int j = 0; j <= t.size(); j++)
            {   
                // 不选
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);

                // 从上一组中选不出来长度为j的序列，不能选
                if(dp[i - 1][j] == 0x3f3f3f3f)  continue;
                
                // 能选的话
                if(t.substr(j, s.size()) == s)
                    dp[i][j + s.size()] = min(dp[i][j + s.size()], dp[i - 1][j] + 1);
            }
        }
    }
    if(dp[n][t.size()] == 0x3f3f3f3f)   cout << -1 << endl;
    else    cout << dp[n][t.size()] << endl;
    return 0;
}
