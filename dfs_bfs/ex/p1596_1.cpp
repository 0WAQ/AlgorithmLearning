#include <iostream>
using namespace std;

// 不需要设置状态数组，图自己可以作为自己的状态数组
const int N = 110;
char g[N][N];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int n, m, ans;

void dfs(int x, int y)
{
    for(int k = 0; k < 8; k++)
    {
        int nx = x + dx[k], ny = y + dy[k];
        
        // 越界或者是旱地（曾经可能可能是水）
        if(nx < 1 || ny < 1 || nx > n || ny > m || g[nx][ny] == '.')
            continue;
        
        g[nx][ny] = '.';
        dfs(nx, ny);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(g[i][j] == 'W')
            {
                ans++;
                g[i][j] = '.';
                dfs(i, j);
            }

    cout << ans << endl;
    return 0;
}