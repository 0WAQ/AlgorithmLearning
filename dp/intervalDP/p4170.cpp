#include <iostream>
#include <cstring>
using namespace std;

const int N = 55;
int dp[N][N];
char s[N];

/**
 * 状态定义：dp[i][j]为字符串子串s[i]~s[j]的最少染色次数
 * 初始状态：dp[i][i] = 1，每个字串只染自己需要1次，其余初始化为inf
 * 状态转移方程：
 *      1.当 i != j，且 s[i] == s[j]时，
 *                  代表该子串的首尾相等，其染色次数是dp[i][j-1]和dp[i+1][j]时顺便多染一个
 *      2.当 i != j，且 s[i] != s[j]时，
 *                  将子串断为两部分染色
*/

int main()
{
    cin >> s + 1;
    int n = strlen(s + 1);

    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++) dp[i][i] = 1;

    // 遍历长度为l的区间时，我们已经得到了所有长度为l-1的区间，那么l就相当于l-1和1的两个并集
    for(int l = 2; l <= n; l++)
        for(int i = 1; i + l - 1 <= n; i++)
        {
            int j = i + l - 1;
            if(s[i] == s[j])
            {
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]);
                continue;
            }
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    cout << dp[1][n] << endl;
    return 0;
}