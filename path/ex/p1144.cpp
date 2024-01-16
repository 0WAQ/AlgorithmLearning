#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

using PII = pair<int, int>;
priority_queue<PII, vector<PII>, greater<PII>> q;
const int N = 1e6 + 5, M = 2e6 + 5, mod = 100003;
int h[N], e[M], ne[M], idx;
int dist[N], ans[N];
bool st[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;;
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
            if(d + 1 < dist[j]) // 第一次找到最短边
            {
                dist[j] = d + 1;
                ans[j] = ans[ver]; //到0~j的边数和0~ver再从ver~j的边数是一样的（边数指的是最短的）
                q.push({dist[j], j});
            }
            else if(d + 1 == dist[j])   // 之后每次找到相等的边
            {
                ans[j] += ans[ver]; // 之后每找到一次就甲ans[ver]次
                ans[j] %= mod;
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    ans[1] = 1; // 第一个点到自己只有一条路（不算自环）
    dijkstra();
    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}