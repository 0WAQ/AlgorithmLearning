#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 310;
char g[N][N];
bool flag[N][N];
int n, k, f = 2, t, ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct node
{
    int x, y, t;
    node() {}
    node(int x, int y, int t) : x(x), y(y), t(t) {}
};

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    queue<node> q;

    node now(3, 3, 0);
    flag[now.x][now.y] = true;
    q.push(now);    

    while (!q.empty())
    {
        now = q.front();
        q.pop();

        if (now.t == k)
            f = 1;
        if (now.t == 2 * k)
            f = 0;

        // 除了上下左右外，还可以原地停留等待
        // 等待
        if (f)
            q.push(node(now.x, now.y, now.t + 1));

        // 遍历四个方向
        for (int i = 0; i < 4; i++)
        {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            // 越界或者已经走过(本体)
            if (nx < 1 || ny < 1 || nx > n || ny > n || flag[nx][ny])
                continue;

            int v = 1;
            // 判断有没有障碍
            for (int xx = nx - f; v && (xx <= nx + f); xx++)
                for (int yy = ny - f; yy <= ny + f; yy++)
                    // 并且不会因为胖而被堵住
                    if (xx < 1 || xx > n || yy < 1 || yy > n || g[xx][yy] == '*')
                    {
                        v = 0;
                        break;
                    }

            if (v) // 没有障碍
            {
                // 如果已经到达终点，直接输出返回
                if (nx == n - 2 && ny == n - 2)
                {
                    cout << now.t + 1 << endl;
                    return 0;
                }

                q.push(node(nx, ny, now.t + 1));
                flag[nx][ny] = true;
            }
        }
    }
    return 0;
}