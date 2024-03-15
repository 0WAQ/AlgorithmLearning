// 天梯赛L2-003:月饼:https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805071789801472?type=7&page=0
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;

struct Node
{
    double a;  // 库存
    double w;   // 单价
    double s;   // 总售价

}v[1010];

bool cmp(const Node& l, const Node& r)
{
    return l.w > r.w;
}

int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i].a;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i].s;
        v[i].w = v[i].s / v[i].a;
    }

    // 对单价从大到小排序
    sort(v + 1, v + n + 1, cmp);

    double ans = 0;
    // 从单价大到小选的，一定最优（贪心）
    for(int i = 1; i <= n; i++)
    {
        // 当前库存小于等于m时，选
        if(v[i].a <= m)
        {
            m -= v[i].a;
            ans += v[i].s;
        }
        else
        {
            ans += v[i].w * m;
            break;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}