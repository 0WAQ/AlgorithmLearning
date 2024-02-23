// p2758
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2010;
int dp[N][N];
char a[N], b[N];

/**
 * 状态定义：dp[i][j] = x 串a的前i个字符变为串b的前j个字符最少经过x次
*/

int main()
{
    cin >> a + 1 >> b + 1;
    int n = strlen(a + 1), m = strlen(b + 1);

    // 处理空串的情况    
    for(int i = 1; i <= n; i++) dp[i][0] = i;
    for(int j = 1; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])    // 不需要进行操作
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1});
                
    cout << dp[n][m] << endl;
    return 0;
}