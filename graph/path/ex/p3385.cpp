// 【模板】负环
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2e3 + 5, M = 6e3 + 5;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];    // 从起点到当前点的最短路包含的边数
bool st[N];
int n, m, T;

void add(int a, int b, int c = 0)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa()
{
    memset(cnt, 0, sizeof(cnt));
    memset(st, 0, sizeof(st));
    memset(dist, 0x3f, sizeof(dist));

    queue<int> q;
    dist[1] = 0;
    q.push(1);
    st[1] = true;
    cnt[1] = 1;

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[t] + w[i] < dist[j])    // 满足条件说明
            {
                // cnt[j] = cnt[t] + 1;
                // if(cnt[j] >= n) // 从j到起点的最短路条数大于等于n，有环
                // {
                //     cout << "YES";
                //     return;
                // }

                dist[j] = dist[t] + w[i];;
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;

                    cnt[j] ++;
                    if(cnt[j] >= n)
                    {
                        cout << "YES";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO";
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> T;
    while (T--)
    {
        memset(h, -1, sizeof(h));
        memset(ne, 0, sizeof(ne));
        memset(e, 0, sizeof(e));
        memset(w, 0, sizeof(0));
        idx = 0;

        cin >> n >> m;
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
            if (c >= 0)
                add(b, a, c);
        }
        spfa();
        cout << endl;
    }
    return 0;
}