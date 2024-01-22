// 跑路
#include <iostream>
#include <cstring>
using namespace std;

const int N = 55;
int g[N][N];
bool st[N][N][N];
int n, m;

void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        // u和v相邻，边长为1米，2^0(利用倍增的思想: 2^t = 2^(t-1) + 2^(t-1) )
        st[u][v][0] = true;
    }

    // 两点间，只要它们的距离是2^t那么只需1s就可以到达
    for(int t = 1; t <= 32; t++)    // 用来枚举1,2,4,8,16.....
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                // 判断以k为中转站，是否有倍增的路径
                if(st[i][k][t - 1] && st[k][j][t - 1])
                {
                    st[i][j][t] = true;
                    g[i][j] = 1;
                }
    floyd();
    cout << g[1][n] << endl;
    return 0;
}