//  [传智杯 #2 决赛] 传送门
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

const int N = 105, M = N * N;
int g[N][N], G[N][N];
int n, m;

void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void init()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            G[i][j] = g[i][j];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }

    floyd();

    int ans = INT_MAX;
    // 暴力枚举
    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= x; y++) // x到y与y到x的最短路是一样的
        {
            init();
            G[x][y] = G[y][x] = 0;  // x与y建传送门

            // 不需要对所有点做最短路，只需要对使用了x和y的路做最短路
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    G[i][j] = min(G[i][j], G[i][x] + G[x][j]);
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    G[i][j] = min(G[i][j], G[i][y] + G[y][j]); 
               
            int res = 0;
            for(int i = 1; i <= n; i++)
                for(int j = 1; j < i; j++)  // 题意：x与y只需要统计一次
                    res += G[i][j];
            ans = min(ans, res);
        }
    cout << ans << endl;
    return 0;
}