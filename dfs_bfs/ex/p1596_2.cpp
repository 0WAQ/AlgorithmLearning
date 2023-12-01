#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

const int N = 110;
char g[N][N];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int n, m, ans;

void bfs(int i, int j)
{
    queue<node> q;

    q.push(node{i, j});
    g[i][j] = '.';

    while(!q.empty())
    {
        node cur = q.front();
        q.pop();

        for(int k = 0; k < 8; k++)
        {
            int nx = cur.x + dx[k], ny = cur.y + dy[k];
            if(nx < 1 || ny < 1 || nx > n || ny > m || g[nx][ny] == '.')
                continue;

            q.push(node{nx, ny});
            g[nx][ny] = '.';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(g[i][j] == 'W')
            {
                ans++;
                bfs(i, j);
            }
    cout << ans << endl;
    return 0;
}