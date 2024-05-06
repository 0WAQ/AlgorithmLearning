// 乌龟棋  
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), b(5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    vector<vector<vector<vector<int>>>> f(b[1] + 1, 
                                          vector<vector<vector<int>>>(b[2] + 1, 
                                          vector<vector<int>>(b[3] + 1, 
                                          vector<int>(b[4] + 1
                                          ))));
    
    /**
     * ※不需要额外一维用来表示位置，题中说明了，用完所有牌一定能到达终点，所以考虑的应该是四种牌的排列
     * 状态表示：f[i][j][k][l]是4中牌各用了i、j、k、l时的得分
     * 属性：Max
     * 初始状态：f[0][0][0][0] = a[1]，一开始就在起点
     * 最终状态：f[b[1]][b[2]][b[3]][b[4]]
     * 状态转移：每种状态f[i][j][k][l]在四种牌中转移而来的
    */

    f[0][0][0][0] = a[1];
    for(int i = 0; i <= b[1]; i++)
        for(int j = 0; j <= b[2]; j++)
            for(int k = 0; k <= b[3]; k++)
                for(int l = 0; l <= b[4]; l++)
                {
                    // 当前的位置
                    int r = 1 + 1 * i + 2 * j + 3 * k + 4 * l; // 一开始在1

                    if(i) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l] + a[r]);
                    if(j) f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l] + a[r]);
                    if(k) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l] + a[r]);
                    if(l) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1] + a[r]);
                }
    cout << f[b[1]][b[2]][b[3]][b[4]] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}