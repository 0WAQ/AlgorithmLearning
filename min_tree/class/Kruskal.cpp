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
    sort(e + 1, e + m + 1);

    for(int i = 1; i <= m; i++)
    {
        int pa = find(e[i].a);
        int pb = find(e[i].b);

        if(pa != pb)
        {
            p[pa] = pb;
            res += e[i].c;
            cnt++;
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