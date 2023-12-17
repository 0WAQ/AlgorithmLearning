#include <iostream>
using namespace std;;

const int N = 105;
int g[N][N];
int dis[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int r, c, ans;

int dfs(int x, int y)
{
    if(dis[x][y]) 
        return dis[x][y];
    dis[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if(nx < 1 || nx > r || ny < 1 || ny > c || g[nx][ny] >= g[x][y])
            continue;
        
        dfs(nx, ny);
        dis[x][y] = max(dis[x][y], dis[nx][ny] + 1);    
    }
    return dis[x][y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> r >> c;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin >> g[i][j];
    
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}