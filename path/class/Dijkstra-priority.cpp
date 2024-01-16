/*
    Dijkstra算法堆优化
    时间复杂度：O((m + n)*logm)
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

priority_queue<PII, vector<PII>, greater<PII>> q;   // 小根堆
const int N = 1e5 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
int n, m, s;

// 创建邻接表
void add(int a, int b, int c)
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    // 初始化
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.push({0, s});
    
    while(q.size())
    {
        auto t = q.top();   // q是小根堆，堆顶元素一定是最小的
        q.pop();

        int ver = t.second, distance = t.first;
        
        // 一个点可以重复入队，之后入队的点不是最小（可能相等）的
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(distance + w[i] < dist[j])
            {
                dist[j] = distance + w[i];
                q.push({dist[j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n >> m >> s;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dijkstra();
    for(int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}