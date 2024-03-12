// 天梯赛题目集L2-001：https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805073643683840?type=7&page=0
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 510, M = N * N;
int h[N], e[M], w[M], ne[M], idx;

// v：点权，num：点权之和，path：路径，cnt：最短路条数
int dist[N], v[N], path[N], cnt[N], num[N];
vector<int> p;
bool st[N];
int n, m, s, d;
priority_queue<PII, vector<PII>, greater<PII>> q;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));

    q.push({0, s});
    dist[s] = 0;

    cnt[s] = 1; // 起点到自己有一条路径（不算自环）
    num[s] = v[s];  // 一开始的点权之和只有起点

    while(q.size())
    {
        int t = q.top().second;
        q.pop();
        
        if(st[t])   continue;
        st[t] = true;

        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                q.push({dist[j], j});

                cnt[j] = cnt[t]; // 更新最短路条数，详情看p1144最短路计数
                path[j] = t;    // 记录路径
                num[j] = num[t] + v[j]; // 记录点权之和
            }
            else if(dist[j] == dist[t] + w[i]) // 边权相同
            {
                cnt[j] += cnt[t]; // 更新最短路条数

                if(num[j] < num[t] + v[j])
                {
                    num[j] = num[t] + v[j]; // 更新救援队数量
                    path[j] = t;    // 更新路径
                }
            }
        }
    }
}

// 本题输出格式较为严格，最后不能有空格
void get_path(int x, int y)
{
    if(x == y)
    {
        p.push_back(x);
        return;
    }
    get_path(x, path[y]);
    p.push_back(y);
}

int main()
{
    cin >> n >> m >> s >> d;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    memset(h, -1, sizeof(h));

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dijkstra();
    
    cout << cnt[d] << ' ' << num[d] << endl;

    get_path(s, d);
    for(int i = 0; i < p.size(); i++)
        if(i < p.size() - 1)
            cout << p[i] << ' ';
        else
            cout << p[i];
    cout << endl;

    return 0;
}