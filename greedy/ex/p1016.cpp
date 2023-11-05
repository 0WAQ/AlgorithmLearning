#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct node
{
    double d, p;
    node(double d, double p) : d(d), p(p) {}
    bool operator<(node t)
    {
        return this->p < t.p;
    }
};

vector<node> a;
double d1, c, d2, P;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> d1 >> c >> d2 >> P >> n;

    double ans = 0;

    // 第一个油站是出发城市
    a.push_back(node(0, P));

    double x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a.push_back(node(x, y));
    }

    double c0 = 0; // 当前汽车的油量
    for (auto i = a.begin(); i != a.end(); i++)
    {
        // 寻找下一个油价小于等于当前油价的油站（中间油站的油价一定大于该油站）
        auto tar = find_if(i + 1, a.end(), [i](node t)
                           { return t.p <= i->p; });

        // 存在这样的油站且加满油能够到达这个油站
        if (tar != a.end() && c * d2 >= tar->d - i->d)
        {
            // 那么加油直到刚好可以到该油站（不加油）
            auto c1 = (tar->d - i->d) / d2;           // 需要的油量
            ans += (c0 >= c1 ? 0 : (c1 - c0) * i->p); // 计算油费
        }
        else // 否则到不了该油站或者没有更便宜的油站
        {
            // 那么加满油（因为中间的油站的油价一定大于当前油价）
            ans += (c - c0) * i->p; // 计算油费
            c0 = c;                 // 加满油

            // 找到最远能够到达的油站
            double m = c * d2 + i->d; // 最远能够到达的距离（距离出发点的）
            // 找到最后一个小于等于m的油站(第一个大于等于m的油站,注意边界)，即为最远油站
            auto md = find_if(i + 1, a.end(), [i](node t)
                              { return t.d >= i->d; });
            if (md->d != m) // x ---- m(如果没有等于m的油站) ---- y，那么md应该--
                md--;
            // 从当前油站与最远油站之间找到一个油价最便宜的油站
            tar = min_element(i + 1, md + 1);
            // 走到改该油站
            c0 -= (tar->d - i->d) / d2;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}