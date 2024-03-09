#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

using PII = pair<int, int>;
priority_queue<PII, vector<PII>, greater<PII>> q;
const int N = 1010, M = 10010 * 2;  // 无向图
int h[N], e[M], ne[M], w[M], idx;
int dist[N], c[N], path;
bool st[N];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q.push({dist[1], 1});

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

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    memset(h, -1, sizeof(h));

    while(m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w + c[b]);
        add(b, a, w + c[a]);    // 双向边，点权附加
    }
    dijkstra();
    cout << dist[n] - c[n] << endl;
    return 0;
}