#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

const int N = 10;
const double PI = 3.1415926535;
double x[N], y[N], r[N], xa, ya, xb, yb, ans = numeric_limits<double>::min();;
bool st[N];
int n;

double getR(int k)
{
    // 计算当前点距离四个边的长度
    double s1 = min(abs(x[k] - xa), abs(x[k] - xb));
    double s2 = min(abs(y[k] - ya), abs(y[k] - yb));

    double t = min(s1, s2);

    // 计算距离每一个点的距离
    for(int i = 1; i <= n; i++)
    {
        if(i != k && st[i])  // 不是同一个点 并且 该点已被滴下
        {
            double d = sqrt((x[k] - x[i]) * (x[k] - x[i]) + (y[k] - y[i]) * (y[k] - y[i]));
            // 要确保现在要滴的点不在之前的点里面(既当前点到第i个点的距离小于第i个点的n半径), 若在里面，则将当前点的半径置0
            t = min(t, max(d - r[i], 0.0));
        }
    }
    return t;
}

void dfs(double s, int k)
{
    if(k == n)
    {
        ans = max(ans, s);
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            r[i] = getR(i);
            st[i] = true;
            dfs(s + PI * r[i] * r[i], k + 1);
            st[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    cin >> xa >> ya >> xb >> yb;

    double ss = abs(xa - xb) * abs(ya - yb);

    for (int i = 1; i <= n; i++)
       cin >> x[i] >> y[i];

    dfs(0, 0);
    printf("%d\n", int(ss - ans + 0.5)); // +0.5 四舍五入
    return 0;
}