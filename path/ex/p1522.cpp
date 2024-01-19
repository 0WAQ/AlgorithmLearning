// [USACO2.4] 牛的旅行 Cow Tours
#include <cmath>
#include <iostream>
using namespace std;

const int N = 155;
int fa[N], x[N], y[N];
double d[N][N], maxd[N], ad[N];
int n;

void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x) 
{ 
    return fa[x] == x ? x : fa[x] = find(fa[x]); 
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    fa[y] = x;
}

bool together(int x, int y) 
{ 
    return find(x) == find(y); 
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    cin >> n;
    init();
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
        
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (i == j)
                d[i][j] = 0;
            else if (c == '1')
            {
                d[i][j] = dist(x[i], y[i], x[j], y[j]);
                merge(i, j);
            }
            else
                d[i][j] = 1 << 30;
        }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (together(i, j))
                maxd[i] = max(maxd[i], d[i][j]);
        ad[find(i)] = max(ad[find(i)], maxd[i]);
    }

    double ans = 1 << 30;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (!together(i, j))
                ans = min(ans,
                          max(maxd[i] + maxd[j] + dist(x[i], y[i], x[j], y[j]),
                              max(ad[find(i)], ad[find(j)])));

    printf("%.6lf\n", ans);
    return 0;
}