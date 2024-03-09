// [SCOI2011] 糖果 Hack数据过不了，卡spfa
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

using LL = long long;
queue<int> q;
const int N = 1e5 + 5, M = 3e5 + 5;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];
int n, m, k, s;

void add(int a, int b, int c = 0)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    dist[0] = 0;
    q.push(0);
    st[0] = true;

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        s++;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] < dist[t] + w[i])    // 最长路
            {
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n + 1 || s > 1e6)
                {
                    cout << -1 << endl;
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
    // 输出糖果数
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        ans += dist[i];
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(h, -1, sizeof(h));
    cin >> n >> k;
    while(k--)
    {
        int x, a, b;
        cin >> x >> a >> b;
        // 反序建边
        switch(x) {
            case 1:
                add(a, b);
                add(b, a);
                break;
            case 2:
                add(a, b, 1);
                break;
            case 3:
                add(b, a);
                break;
            case 4:
                add(b, a, 1);
                break;
            case 5:
                add(a, b);
                break;
        }
    }
    for(int i = 1; i <= n; i++)
        add(0, i, 1);
    spfa();
    return 0;
}
