#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

using PII = pair<int, int>;
priority_queue<PII, vector<PII>, greater<PII>> q;
const int N = 1e4 + 5, M = 2e5 * 2 + 5, mx = 1e9 + 1;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], f[N];
bool st[N];
int n, m, b;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool dijkstra(int x)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));

    if(x < f[1])    return false;   // 先判断能不能过起点
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
            if(f[j] <= x && d + w[i] < dist[j]) // 在所有城市的费用小于x的情况下有路可走
            {
                dist[j] = d + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return b >= dist[n];
}

int main()
{
    cin >> n >> m >> b;
    for(int i = 1; i <= n; i++)
        cin >> f[i];
    memset(h, -1, sizeof(h));
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    if(!dijkstra(mx))
    {
        cout << "AFK" << endl;
        return 0;
    }

    int l = 1, r = mx, ans = r;
    while(l <= r)
    {
        int mid = (l + r) >> 1; // 二分答案，mid就是每条路径的最大费用
        if(dijkstra(mid))   // 相当于是一道二分题，check函数是最短路
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}