// [TJOI2007] 线段
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> l(n + 1), r(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];

    // 发现走到当前行时，最后停在左边还是右边？并且发现，也可以从上一行的左边或者右边转移过来
    // 故有两维，第一位表示行，第二维用0、1分别表示左和右

    /**
     * 状态定义：f[i][0]和f[i][1]分别表示走完第i行，停在左边、右边的最短长度
     * 属性：Min
     * 初始状态：f[1][0] = r[1] - 1 + r[1] - l[1]
     *          f[1][1] = r[1] - 1
     * 最终状态：min(f[n][0], f[n][1])
     * 
     * 状态计算：
     *      f[i][0]: 1.当从f[i - 1][0]转移来时：相当于从 l[i - 1] 走到 r[i] 再走到 l[i]
     *                   f[i - 1][0] + abs(l[i - 1] - r[i]) + r[i] - l[i]
     * 
     *               2.当从f[i - 1][1]转移来时：相当于从 r[i - 1] 走到 r[i] 再走到 l[i]
     *                   f[i - 1][1] + abs(r[i - 1] - r[i]) + r[i] - l[i]
     *              
     *               从上一行走到下一行长度为1
     *  
     *      f[i][1]：同理
    */
    
    vector<vector<int>> f(n + 1, vector<int>(2));

    f[1][1] = r[1] - 1;
    f[1][0] = r[1] + r[1] - l[1] - 1;

    for(int i = 2; i <= n; i++)
    {
        f[i][0] = min(f[i - 1][0] + abs(l[i - 1] - r[i]) + r[i] - l[i], 
                      f[i - 1][1] + abs(r[i - 1] - r[i]) + r[i] - l[i]) + 1;
        f[i][1] = min(f[i - 1][0] + abs(l[i - 1] - l[i]) + r[i] - l[i],
                      f[i - 1][1] + abs(r[i - 1] - l[i]) + r[i] - l[i]) + 1;
    }

    // 最后还要到点(n, n)
    cout << min(f[n][0] + n - l[n], f[n][1] + n - r[n]) << endl;
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