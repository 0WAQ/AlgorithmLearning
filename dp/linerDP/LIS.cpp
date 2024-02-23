// B3637-最长上升子序列
#include <iostream>
using namespace std;

const int N = 5050;
int a[N], dp[N];
int n;

/**
 *  状态定义：dp[i]是以第i个元素为结尾的上升子序列的长度0
*/

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], dp[i] = 1; // 初始状态
    
    // 状态转移方程
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i - 1; j++)
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}