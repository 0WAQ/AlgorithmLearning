// [NOIP1996 提高组] 挖地雷
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 25;
int dp[N], w[N], g[N][N], pre[N];
int n;

/**
 * 状态定义：dp[i]以第i个地窖为结尾的最多数量
 * 初始状态：dp[i] = w[i]
*/

void print()
{
    
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i], dp[i][i] = w[i];
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }

    
    return 0;
}