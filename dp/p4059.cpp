// [Code+#1] 找爸爸
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    map<char, int> mp;
    mp['A'] = 1, mp['T'] = 2, mp['G'] = 3, mp['C'] = 4;

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++) a[i] = mp[s1[i - 1]];
    for(int i = 1; i <= m; i++) b[i] = mp[s2[i - 1]];

    vector<vector<ll>> d(5, vector<ll>(5));
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            cin >> d[i][j];
    
    ll A, B;
    cin >> A >> B;

    /**
     * 状态表示：f[i][j][k]是A和B分别匹配了前i个和前j个，最后结尾处空格的状态的最大相似度
     *          k：0代表没有空格，1、2分别代表空格在A和B中
     * 属性：Max
     * 初始状态：
     * 最终状态：max{ f[n][m][] }
     * 状态计算：
     *      f[i][j][0] = max(f[i - 1][j - 1][0], f[i - 1][j - 1][1], f[i - 1][j - 1][0]) + d[i][j]
     *      f[i][j][1] = max(f[i][j - 1][0] - A, f[i][j - 1][1] - B, f[i][j - 1][2] - A);
     *      f[i][j][2] = max(f[i - 1][j][0] - A, f[i - 1][j][1] - A, f[i - 1][j][2] - B);
    */
    vector<vector<vector<ll>>> f(n + 1, vector<vector<ll>>(m + 1, vector<ll>(3)));

    // 初始化
    for(int i = 1; i <= n; i++) {
        f[i][0][0] = f[i][0][1] = -0x3f3f3f3f;
        f[i][0][2] = -A - B * (i - 1);
    }
    for(int j = 1; j <= m; j++){
        f[0][j][0] = f[0][j][2] = -0x3f3f3f3f;
        f[0][j][1] = -A - B * (j - 1);
    }
    f[0][0][1] = f[0][0][2] = -0x3f3f3f3f;


    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            f[i][j][0] = max({f[i - 1][j - 1][0], f[i - 1][j - 1][1], f[i - 1][j - 1][2]}) + d[a[i]][b[j]];
            f[i][j][1] = max({f[i][j - 1][0] - A, f[i][j - 1][1] - B, f[i][j - 1][2] - A});
            f[i][j][2] = max({f[i - 1][j][0] - A, f[i - 1][j][1] - A, f[i - 1][j][2] - B});
    }

    cout << max({f[n][m][0], f[n][m][1], f[n][m][2]}) << endl;
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