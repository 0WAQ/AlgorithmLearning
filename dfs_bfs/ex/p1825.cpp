#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int x, y, t;
};

const int N = 310;
char g[N][N];
bool st[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
queue<node> q;

void bfs()
{
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        // 如果是终点，直接返回
        if (g[cur.x][cur.y] == '=')
            cout << cur.t << endl;

        // 是传送门,直接修改为下一个传送门的坐标
        if (g[cur.x][cur.y] >= 'A' && g[cur.x][cur.y] <= 'Z')
        {
            auto door = [&]() 
            {
                for(int i = 1; i <= n; i++)                
                    for(int j = 1; j <= m; j++)                    
                        if(g[i][j] == g[cur.x][cur.y] && (i != cur.x || j != cur.y))
                        {
                            cur.x = i, cur.y = j;
                            return;
                        }             
            };

            door();
        }

        for (int k = 0; k < 4; k++)
        {
            int nx = cur.x + dx[k], ny = cur.y + dy[k], nt = cur.t + 1;

            // 越界、已走过、是障碍 不能走
            if (nx < 1 || ny < 1 || nx > n || ny > m || st[nx][ny] || g[nx][ny] == '#')
                continue;

            q.push(node{nx, ny, nt});
            st[nx][ny] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == '@')
            {
                q.push(node{i, j, 0});
                st[i][j] = true;
            }
        }
    bfs();
    return 0;
}
