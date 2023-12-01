// 0的连通块
#include <iostream>
#include <cstring>
using namespace std;

const int N = 35;
int a[N][N], st[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

void dfs(int x, int y)
{
    if(x < 0 || y < 0 || x > n + 1 || y > n + 1 || st[x][y])
        return;

    st[x][y] = 1;
    for(int k = 0; k < 4; k++)
    {
        int nx = x + dx[k], ny = y + dy[k];
        dfs(nx, ny);    // 同理，先往下递归一层，再判断是否越界
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
        
    memcpy(st, a, sizeof a);

    dfs(0, 0);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            if(st[i][j] == 0)    cout << 2 << ' ';
            else    cout << a[i][j] << ' '; 
        cout << endl;
    }
    return 0;
}