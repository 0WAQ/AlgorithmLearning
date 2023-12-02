#include <iostream>
#include <limits>
#include <cmath>
#include <map>
using namespace std;

#define DIS(x1, y1, x2, y2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

const int N = 20;
double sx[N], sy[N];
bool st[N];
int n;
double ans = numeric_limits<double>::max();

void dfs(int k, double dis, double x, double y)
{
    if(dis > ans)   return; // 最优性剪枝
    if(k == n)
    {
        ans = ans < dis ? ans : dis;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            st[i] = true;
                dfs(k + 1, dis + DIS(x, y, sx[i], sy[i]), sx[i], sy[i]);
            st[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> sx[i] >> sy[i];

    dfs(0, 0, 0, 0);

    printf("%.2lf\n", ans);
    return 0;
}