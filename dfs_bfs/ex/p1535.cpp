#include <iostream>
#include <cmath>
using namespace std;

const int N = 110;
char g[N][N];
bool st[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m, t, r1, c1, r2, c2;
int ans;

void dfs(int x, int y, int nowt)
{
    // 真就是你打死也想不到的优化
    if(abs(r2 - x) + abs(c2 - y) + nowt > t)
        return;
    if(x == r2 && y == c2 && nowt == t)
    {
        ans++;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny] || g[nx][ny] == '*')
            continue;
        dfs(nx, ny, nowt + 1);
    }
}

int main()
{
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    cin >> r1 >> c1 >> r2 >> c2;

    dfs(r1, c1, 0);
    cout << ans << endl;
    return 0;
}