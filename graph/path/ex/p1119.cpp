// 灾后重建
#include <iostream>
#include <cstring>
using namespace std;

const int N = 205;
int g[N][N], t[N];
int n, m, q;

void floyd(int k)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(g, 0x3f, sizeof(g));

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> t[i];    // 递增的
    while(m--)
    {
        int i, j, w;
        cin >> i >> j >> w;
        g[i][j] = g[j][i] = w;
    }
    cin >> q;
    int idx = 0; // 当前点
    while(q--)
    {
        int x, y, tt;   // tt也是递增的
        cin >> x >> y >> tt;
        while(t[idx] <= tt && idx < n)
        {
            floyd(idx);
            idx++;
        }
        if(t[x] > tt || t[y] > tt || g[x][y] == 0x3f3f3f3f)
            cout << -1 << endl;
        else
            cout << g[x][y] << endl;
    }
    return 0;
}