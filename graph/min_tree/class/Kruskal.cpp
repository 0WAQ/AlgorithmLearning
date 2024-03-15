/**
 * 时间复杂度: mlogm
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int p[N];
int n, m, res, cnt;

struct edge
{
    int a, b, c;
    bool operator < (const edge& e) {
        return c < e.c;
    }
}e[M];

int find(int a)
{
    if(p[a] != a)   p[a] = find(p[a]);
    return p[a];
}

void kruskal()
{
    // 将所有边从大到小排序
    sort(e + 1, e + m + 1);

    // 从小到大枚举每条边
    for(int i = 1; i <= m; i++)
    {
        // 边的起点与终点所在的连通块
        int pa = find(e[i].a);
        int pb = find(e[i].b);

        // 两个点不在一个连通块中，将其合并成一个
        if(pa != pb)
        {
            p[pa] = pb;
            res += e[i].c;
            cnt++;  // 连通块中的点数加1
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        p[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    kruskal();
    if(cnt < n - 1) cout << "impossible" << endl;
    else    cout << res << endl;

    return 0;
}