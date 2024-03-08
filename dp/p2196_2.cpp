// [NOIP1996 提高组] 挖地雷
#include <iostream>
using namespace std;

const int N = 25;
int a[N], pre[N], dp[N];
bool g[N][N];
int n, maxx, idx;

/**
 * 状态定义：dp[i]: 以i为终点时挖到地雷数量，它的起点其它所有连通的点
 * 状态转移：dp[i] = max({dp[j]}) + a[i]
 * 最终状态：max({dp[i]})
*/

void print(int x)
{
    if(pre[x])  print(pre[x]);
    cout << x << ' ';
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            cin >> g[i][j];
    
    // 以i为终点时的最大值
    for(int i = 1; i <= n; i++)
    {
        // 寻找i的上一个点，找一个最大的dp[j]
        for(int j = 1; j <= i; j++) 
            if(g[j][i] && dp[i] < dp[j])
            {
                dp[i] = dp[j];
                pre[i] = j;
            }
        
        dp[i] += a[i];
        if(dp[i] > maxx)
        {
            maxx = dp[i];
            idx = i;
        }
    }
    print(idx);
    cout << '\n' << maxx << endl;
    return 0;
}