/**
 * SPFA算法：是Bellman-Ford算法的优化
 * 时间复杂度：最好为O(m)，最坏为O(mn), 大多情况下不稳定
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N]; // 用来标记是否在队列中
int n, m;
queue<int> q;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    q.push(1);
    st[1] = true;

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false; // 将t取出来了

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            // 对点j进行松弛操作
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
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
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa();
    if(dist[n] > 0x3f3f3f3f / 2)
        cout << "no path";
    else
        cout << dist[n];
    cout << endl;
    return 0;
}