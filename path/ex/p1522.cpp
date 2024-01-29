// [USACO2.4] 牛的旅行 Cow Tours
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 155;
const double INF = 1e20;
double g[N][N], maxd[N], x[N], y[N];
int n;

double dist(double xi, double yi, double xj, double yj)
{
    return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0); 
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if(i == j) g[i][j] = 0;
            else if(c == '1') g[i][j] = dist(x[i], y[i], x[j], y[j]);
            else g[i][j] = INF;
        }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    // 1.计算maxd和maxd[i]的最大值
    double maxx = 0.0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            if(g[i][j] < INF / 2)   // i和j连通
                maxd[i] = max(maxd[i], g[i][j]);
        maxx = max(maxx, maxd[i]);
    }

    // 2.枚举所有牧区
    double res = INF;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(g[i][j] > INF / 2)   // ij不连通
                res = min(res, maxd[i] + dist(x[i], y[i], x[j], y[j]) + maxd[j]);

    printf("%.6lf\n", max(maxx, res));
    return 0;
}   