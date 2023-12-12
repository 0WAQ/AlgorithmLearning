#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct node {
    int x, y, c, t;
};

const int N = 105, INF = 0x7f7f7f7f;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int g[N][N], val[N][N], n, m, ans = INF;    // val 数组用来优化
queue<node> q;

void bfs()
{
    q.push(node{1, 1, g[1][1], 0});
    val[1][1] = 0;

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y, c = cur.c, t = cur.t;

        if (t > ans)
            continue; // 剪枝

        // 如果是终点
        if (x == m && y == m)
        {
            ans = min(ans, t);
            continue; // 为何不是return
        }

        // 遍历所有方向
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            // 是否越界、已走过
            if (nx < 1 || nx > m || ny < 1 || ny > m )
                continue;

            int cc = g[x][y], nc = g[nx][ny]; // 当前点和下一个点一开始的颜色
            int nnt = val[nx][ny], nt;

            if (cc >= 0 && nc >= 0) // 当前有颜色, 下一个没有颜色
            {
                nt = (cc == nc) ? t : t + 1;
                if (nt < nnt)
                {   
                    q.push(node{nx, ny, nc, nt});
                    val[nx][ny] = nt;
                }
            }
            else if (cc >= 0 && nc < 0) // 当前有颜色, 下一个没有颜色
            {
                nt = t + 2;
                if (nt < nnt)
                {
                    q.push(node{nx, ny, cc, nt});
                    val[nx][ny] = nt;
                }
            }
            else if (cc < 0 && nc >= 0) //  当前没有颜色, 下一个有颜色(x, y肯定使用魔法改变过颜色)
            {
                nt = (c == nc) ? t : t + 1;
                if (nt < nnt)
                {
                    q.push(node{nx, ny, nc, nt});
                    val[nx][ny] = nt;
                }
            }
        }
    }
    return;
}

int main()
{
    memset(g, -1, sizeof(g));
    memset(val, 0x7f, sizeof(val));

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        g[x][y] = c;
    }

    bfs();

    if (ans == INF)
        ans = -1;
    cout << ans << endl;

    return 0;
}