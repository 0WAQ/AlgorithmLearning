// 【模板】差分约束
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<int> q;
const int N = 5e3 + 5, M = 5e4 + 5;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];
int n, m;

void add(int a, int b, int c = 0)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    memset(dist, 0x3f, sizeof(dist));

    dist[0] = 0;
    q.push(0);
    st[0] = true;
    cnt[0] = 1;

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i]) // 目的是确保 dist[j] <= dist[t] + w[i]
            {
                // cnt[j] = cnt[t] + 1;
                // if(cnt[j] >= n + 1) // 添加了一个超级源点
                // {
                //     cout << "No" << endl;
                //     return;
                // }

                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                    cnt[j] ++;
                    if(cnt[j] >= n + 1) // 添加了一个超级源点
                    {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }
    // 有解，输出可行解
    for(int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << endl;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(h, -1, sizeof(h)); 

    cin >> n >> m;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(b, a, c);
    }
    // 或者全部放入队列也行
    for(int i = 1; i <= n; i++)
        add(0, i);
    spfa();
    return 0;
}