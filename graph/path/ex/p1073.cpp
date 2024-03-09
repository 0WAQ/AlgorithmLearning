//  [NOIP2009 提高组] 最优贸易
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<int> q;
const int N = 3e5 + 5, M = 3e6 + 5;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], v;
bool st[N];
int n, m;

void add(int a, int b, int c = 0)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa()
{
    memset(dist, -0x3f, sizeof(dist));

    dist[1] = 0;
    q.push(1);
    st[1] = true;

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] < dist[t] + w[i])    // 这道题其实是最“远”路
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
    cin.tie(0);

    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> v;
        add(i, i + n, -v);  // 买入
        add(i + n, i + 2 * n, v);   // 卖出
    }
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b);
        add(a + n, b + n);
        add(a + 2 * n, b + 2 * n);
        if(c == 2)
        {
            add(b, a);
            add(b + n, a + n);
            add(b + 2 * n, a + 2 * n);
        }
    }
    spfa();
    cout << dist[3 * n] << endl;
    return 0;
}