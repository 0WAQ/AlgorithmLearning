#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, t, to;
};

const int N = 55;
int g[N][N];
bool st[N][N][4];
int dx[4] = {0, 1, 0, -1};   //东南西北 
int dy[4] = {1, 0, -1, 0};   //0 1 2 3
int n, m, sx, sy, fx, fy, sto;
char c;
queue<node> q;

int bfs()
{
    // 终点是障碍物
    if(g[fx][fy] || fx == n || fy == m)   return -1;

    q.push(node{sx, sy, 0, sto});
    st[sx][sy][sto] = true;

    while(!q.empty())
    {
        node cur = q.front();
        q.pop();

        // 到达终点，返回时间
        if(cur.x == fx && cur.y == fy)
            return cur.t;

        // 向左转
        int nto = (cur.to + 4 - 1) % 4;
        if(!st[cur.x][cur.y][nto])
        {
            q.push(node{cur.x, cur.y, cur.t + 1, nto});
            st[cur.x][cur.y][nto] = true;
        }
        
        // 向右转
        nto = (cur.to + 1) % 4;
        if(!st[cur.x][cur.y][nto])
        {
            q.push(node{cur.x, cur.y, cur.t + 1, nto});
            st[cur.x][cur.y][nto] = true;
        }

        // 走的步数
        for(int k = 1; k <= 3; k++)
        {
            int nx = cur.x + dx[cur.to] * k, ny = cur.y + dy[cur.to] * k;

            // 越界、走过(当前位置当前方向)
            if(nx < 1 || nx > n - 1 || ny < 1 || ny > m - 1 || st[nx][ny][cur.to])
                continue;

            // 范围之内越界、有障碍
            bool flag = 0;
            for(int i = nx; i <= nx + 1; i++)
                for(int j = ny; j <= ny + 1; j++)
                    if(i < 1 || i > n || j < 1 || j > m || g[i][j])
                            flag = 1;
            if(flag) break; 

            q.push(node{nx, ny, cur.t + 1, cur.to});
            st[nx][ny][cur.to] = true;
        }
    }

   return -1; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    cin >> sx >> sy >> fx >> fy >> c;

    switch (c)
    {
        case 'E': sto = 0; break;
        case 'S': sto = 1; break;
        case 'W': sto = 2; break;
        case 'N': sto = 3; break;
    }

    cout << bfs() << endl;
    return 0;
}