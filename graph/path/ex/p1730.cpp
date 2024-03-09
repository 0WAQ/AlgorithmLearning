// 最小密度路径
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int N = 55, M = 1010;
int g[N][N][M]; // 定义状态为：从i到j经过x条边的最短路径
int n, m, q;

void floyd()
{
    for(int x = 2; x <= m; x++) // 从2开始，因为边的数量不能为0
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    g[i][j][x] = min(g[i][j][x], g[i][k][x - 1] + g[k][j][1]);
}

int main()
{
    // 决定c++标准是否与相应的c标准同步，即是否使用相同的流缓冲区
    ios::sync_with_stdio(0);

    // 输出同步
    cin.tie(0);    // 解除cin与cout的绑定（即每次执行<<时都会调用flush，刷新缓冲）

    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b][1] = min(g[a][b][1], w);
    }
    floyd();
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        double ans = 0x3f3f3f3f;

        for(int i = 1; i <= m; i++) // 枚举边数，算密度
            if(g[x][y][i] < 0x3f3f3f3f)
                ans = min(ans, (double)g[x][y][i] / i);

        if(ans == 0x3f3f3f3f)
            printf("OMG!\n");   // 这里使用cout会使输出错误，原因：关闭了同步选项，使之变为了两条流
        else
            printf("%.3lf\n", ans);
    }
    return 0;
}