// [USACO08JAN] Cow Contest S
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 105, M = 4505;
bool g[N][N];
int n, m;

void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);  // 能从i走到j
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    floyd();
    int ans = 0;
    for(int i = 1; i <= n; i++) // 枚举所有奶牛
    {
        bool a = 1;  // 先假设i的排名已知
        for(int j = 1; j <= n; j++) // 判断i和j两个奶牛是否有排名
            if(i == j) continue;
            else a = a && (g[i][j] || g[j][i]); // 一旦i和j的排名不确定，a变为0
        if(a)
            ans++;
    }       
    cout << ans << endl;
    return 0;
}