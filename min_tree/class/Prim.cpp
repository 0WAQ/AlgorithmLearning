#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int g[N][N], dist[N], pre[N];
bool st[N];
int n, m;

void getPath()
{
    for(int i = n; i > 1; i--)
        cout << i << ' ' << pre[i] << endl;
}

void prim()
{
    memset(dist, 0x3f, sizeof(dist));

    int res = 0;
    dist[1] = 0;

    for(int i = 1; i <= n; i++)
    {
        int t = -1;

        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }

        if(dist[t] == INF)
        {
            cout << "impossible" << endl;
            return;
        }

        res += dist[t];
        st[t] = true;

        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && dist[j] > g[t][j])
            {
                dist[j] = g[t][j];
                pre[j] = t;
            }
        }
    }

    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(g, 0x3f, sizeof(g));

    cin >> n >> m;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    prim();

    getPath();
    return 0;
}
