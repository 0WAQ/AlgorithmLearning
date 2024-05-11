#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), f(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    /**
     * 状态表示：f[i]以i为结尾的上升子序列的和
     * 属性：Max
     * 初始状态：f[i] = a[i];
     * 最终状态：max({f[i]})
     * 状态计算：同最长上升子序列
    */

    int ans = 0;
    // 遍历上升子序列的结尾，从小到大递推
    for(int i = 1; i <= n; i++) 
    {
        f[i] = a[i];
        // 相当于是以j为中转点，走到i
        for(int j = 1; j < i; j++)
            if(a[i] > a[j]) // 若i所在的值大于j的，就构成一个上升子序列
                f[i] = max(f[i], f[j] + a[i]);  // 在LIC中，求的是长度的最大值；本题中，求的是和的最大值
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}