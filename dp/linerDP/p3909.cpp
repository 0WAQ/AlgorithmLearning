// 导弹拦截Ⅲ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(2));

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    /**
     * 本题不应该按照下标来判断奇偶，
     * 要用导弹发射的位置作为起始位置来判断
     * 
     * 所以，任何一个位置都可以是奇数步或者偶数步
     * 所以增加一维（或者再开一个数组）来表示当前元素的奇偶
     * 
     * 状态表示：如上
     * 属性：Max
     * 初始状态：在原题LIS中f[i] = 1表示以当前元素为结尾的长度是1，
     *          因为长度是1，所以f[i]也表示以当前元素为开始长度是1
     *          后面的遍历可以理解为：是在给i挑选前缀
     * 
     *          在这道题中，可以以任意元素为开始（即第一个导弹）那么f[i][1] = 1
     *          但却不可以将f[i][0]赋为1，因为f[i][0]最少也表示以第2个元素为开始，
     *                                  它应该是从前1个元素（这个元素是奇数）递推而来的
     * 
     * 最终状态：max({f[i][1], f[i][0]})
     * 状态计算：每个元素既可以为奇，也可以为偶，
     *          当为奇时：上升子序列
     *          当为偶时：下降子序列
    */

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        f[i][1] = 1;
        for(int j = 1; j < i; j++)
        {   
            // 奇数步
            if(a[i] > a[j]) f[i][1] = max(f[i][1], f[j][0] + 1);
            // 偶数步
            if(a[i] < a[j]) f[i][0] = max(f[i][0], f[j][1] + 1);
        }
        ans = max({ans, f[i][0], f[i][1]});
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