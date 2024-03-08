#include <iostream>
using namespace std;
using LL = long long;

const int N = 10;
LL dp[N][N * N][1 << N];
int cnt[1 << N], ok[1 << N];    // ok数组保存行内合法状态
int n, k, len;

/**
 * 状态定义：dp[i][k][s]=x：第i行状态为s，总共放了k个国王的情况下，合法的方案总数为x
 * 初始状态：没有放国王
*/

int main() 
{

    cin >> n >> k;
    
    // 统计每一种状态中1的数量(即国王数量) 并且 判断该状态合不合法，相当于一个预处理
    for(int s = 0; s < (1 << n); s++) 
    {
        int tot = 0, t = s;
        while(t) 
        {
            if(t & 1)   tot++;
            t >>= 1;
        }
        cnt[s] = tot;
        
        if(!(((s << 1) | (s >> 1)) & s))    
            ok[len++] = s;
    }

    // k=0时（没有国王可以放），是一种方案
    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++) 
    {
        // 枚举第 i 行可行的状态（全部保存在ok数组中）
        for(int l = 0; l < len; l++) 
        {
            int s1 = ok[l];

            // 枚举第 i - 1 行可行的状态
            for(int r = 0; r < len; r++) 
            {
                int s2 = ok[r];
                
                // 行间合法
                if(!((s2 | (s2 << 1) | (s2 >> 1 )) & s1)) 
                {
                    // 枚举国王数
                    for(int j = cnt[s1]; j <= k; j++) 
                        // if(j - cnt[s1] >= 0)
                            dp[i][j][s1] += dp[i - 1][j - cnt[s1]][s2];
                }
            }
        }
    }

    LL ans = 0;
    for(int i = 0; i < len; i++)
        ans += dp[n][k][ok[i]];
    cout << ans << endl;
    return 0;
}