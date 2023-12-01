#include <iostream>
using namespace std;

const int N = 10;
int g[N][N];
bool st[N][N];
int sx, sy, fx, fy;
int n, m, t;
int ans;

void dfs(int x, int y)
{
    // 越界
    if(x < 1 || x > n || y < 1 || y > n)
        return;
    
    // 到终点
    if(x == fx && y == fy)
    {
        ++ans;
        return;
    }

    /*
     *  ＊＊＊ 不判断下一个点能不能走，转而判断当前点（多一层递归）能不能走(代码量少) 
     */
    if(g[x][y] || st[x][y]) return;

    st[x][y] = 1; // 走了当前点
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    st[x][y] = 0; // 回溯
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    int x, y;
    while(t--)
    {
        cin >> x >> y;
        g[x][y] = 1;
    }

    if(g[fx][fy] == 1)  //  终点可能有障碍，文字游戏真恶心
    {
        cout << 0 << endl;
        return 0;
    }

    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}
