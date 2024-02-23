// 最长公共子序列-lcLCR095
#include <iostream>
#include <cstring>
using namespace std;

/**
 * 状态定义：dp[i][j]是 第一个串的前i位 与 第二个串的前j位 的LCS的长度
*/

const int N = 1010;
string s1, s2;
int dp[N][N];   // 初始状态为0

int main()
{  
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s1[i - 1] == s2[j - 1])  // s1 和 s2 是从 0 开始输入的
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    cout << dp[n][m] << endl;
    return 0;
}