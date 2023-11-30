#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct node {
    int x, y, t;
};

const int N = 310;
int g[N][N]; // g中存的是陨石降落的时间，如有多个陨石，以最早为准
int dx[5] = {0, 0, 0, -1, 1}; // 包括陨石刚好落下的点和周围四个
int dy[5] = {0, 1, -1, 0, 0};
bool st[N][N];
int n, m;
queue<node> q;

int bfs()
{
    q.push(node{0, 0, 0});
    st[0][0] = true;

    while(!q.empty())
    {
        node cur = q.front();
        q.pop();

        // 当前点安全
        if(g[cur.x][cur.y] == -1)    return cur.t;

        for(int k = 1; k < 5; k++)
        {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            int nt = cur.t + 1;

            // 越界、已走过或者 有障碍(有陨石降落并且走到该点时陨石已经降落)
            if(nx < 0 || nx >= m || ny < 0 || ny >= m || st[nx][ny] || (g[nx][ny] != -1 && g[nx][ny] <= nt))
                continue;
            
            q.push(node{nx, ny, nt});
            st[nx][ny] = true;
        }
    }
    return -1;
}

int main()
{
    cin >> m;
    int x, y, t;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            g[i][j] = -1;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> t;
        for(int k = 0; k < 5; k++)
        {
            // 没有越界并且(没有陨石降落过或者降落的陨石早于现在的陨石)，标记
            if(x + dx[k] >= 0 && y + dy[k] >= 0 && 
                        (g[x + dx[k]][y + dy[k]] == -1 || g[x + dx[k]][y + dy[k]] > t))
                g[x + dx[k]][y + dy[k]] = t;
        }
    }
    int ans = bfs();
    cout << ans << endl;
    return 0;
}