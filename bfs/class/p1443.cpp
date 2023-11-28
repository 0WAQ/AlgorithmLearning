#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 410;
int g[N][N];
int n, m, xx, yy;

struct node {
    int x, y;
    node() {}
    node(int x, int y) : x(x), y(y) {}
};

int dx[8] = {-2, -2,  2,  2,  1,  1, -1, -1};
int dy[8] = {-1,  1, -1,  1, -2,  2,  2, -2};

int main()
{
    cin >> n >> m >> xx >> yy;

    queue<node> q;
    memset(g, -1, sizeof g);

    g[xx][yy] = 0;
    q.push(node(xx, yy));

    while(!q.empty())
    {
        node now = q.front();
        q.pop();

        for(int i = 0; i < 8; i++)
        {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] != -1) // 越界或者已经被走过
                continue;
            
            q.push(node(nx, ny));
            g[nx][ny] = g[now.x][now.y] + 1;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            printf("%5d", g[i][j]);
        printf("\n");
    }
    cout << endl;
    return 0;
}