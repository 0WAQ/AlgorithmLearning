/**
 * SPFA算法：是Bellman-Ford算法的优化
 * 时间复杂度：最好为O(m)，最坏为O(mn), 大多情况下不稳定(看出题人卡不卡)
 * 
 * 一. 判断负环的方法:
 *     1. 统计每个点的入队次数,如果某点入队n次,则存在负环
 *        (再bellman-ford算法中,一个点最多被更新n-1次)
 *     2. 统计每个点的最短路中包含的边数,如果某点的最短路所包含的边数大于等于n,则存在负环
 *        (一条路径包含n边,则包含n+1个点,至少有两个点相同)
 * 
 * 二. spfa求负环时,时间复杂度稳定在 O(nm),可能会超时
 *     1. 当出现这种情况时,使判断条件为2n, 就认为图中有很大可能存在负环
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int dist[N], cnt[N];    // cnt: 每个点的最短路所包含的边数
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
    cnt[1] = 0; // 1.
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
                // 2.
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n)
                {
                    cout << "有负环" << endl;
                    return;
                }

                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    cout << "没有负环" << endl;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

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