/**
 * 不需要对所有点各做一次prim
 * 只要对任意一点做一次就行
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int g[N][N], dist[N];
bool st[N];
int n, a, res;

int prim(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    res += a;

    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        res += dist[t];
        st[t] = true;

        for(int j = 1; j <= n; j++)
            if(!st[j] && g[t][j] < dist[j])
               dist[j] = g[t][j];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(g, 0x3f, sizeof(g));

    cin >> a >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == 0)    g[i][j] = a;
        }

    // 所有物品按原价买
    cout << min(a * n, prim(1)) << endl;

    return 0;
}
