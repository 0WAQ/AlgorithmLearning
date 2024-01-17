// 飞行路径----分层图
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

using PII = pair<int, int>;
priority_queue<PII, vector<PII>, greater<PII>> q;
const int N = 2e4 * 11 + 5, M = 1e5 * 21 + 11;   // 最多11层，但是层与层之间也有连接
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
int n, m, k, s, t;

void add(int a, int b, int c = 0)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.push({dist[s], s});

    while(q.size())
    {
        auto t = q.top();
        q.pop();

        int ver = t.second, d = t.first;
        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d + w[i] < dist[j])
            {
                dist[j] = d + w[i];
                q.push({dist[j], j});
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));
    
    cin >> n >> m >> k;
    cin >> s >> t;
    // 建k + 1层图，原图为第0层
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
        for(int j = 1; j <= k; j++)
        {
            // 各层内部间也要连接
            add(a + j * n, b + j * n, c);
            add(b + j * n, a + j * n, c);
            // 层与层之间
            add(a + (j - 1) * n, b + j * n);
            add(b + (j - 1) * n, a + j * n);
        }
    }
    // 有可能在中间层走到终点，所以把终点之间连接起来
    for(int j = 1; j <= k; j++)
        add(t + (j - 1) * n, t + j * n);

    dijkstra();
    // 终点是t + k * n
    cout << dist[t + k * n] << endl;
    return 0;
}
