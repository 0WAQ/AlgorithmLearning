#include <iostream>
using namespace std;

const int N = 105;
char g[N][N];
bool ans[N][N];
char s[] = " yizhong";
int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int n;

bool dfs(int x, int y, int k, int m) // k是下一个字母的位置
{
    // 选够7个字母了
    if (k > 7)
    {
        ans[x][y] = 1;
        return true;
    }

    // 下一个字母的坐标
    int nx = x + dx[m], ny = y + dy[m];

    // 越界
    if (nx < 1 || nx > n || ny < 1 || ny > n)
        return false;

    // 下一个字母正好是要找的字母
    if (g[nx][ny] == s[k] && dfs(nx, ny, k + 1, m))
    {
        ans[x][y] = true;
        return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < 8; k++) // 将向八个方向搜索放在递归外面
                if (g[i][j] == 'y')
                    dfs(i, j, 2, k);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans[i][j])
                cout << g[i][j];
            else
                cout << '*';
        }
        cout << endl;
    }
    return 0;
}