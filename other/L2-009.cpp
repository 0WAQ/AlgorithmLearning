// 重写cmp函数
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4 + 5;
struct node {
    int id, cnt;
    double p;
}a[N];
int n, m;

bool cmp(node& l, node& r)
{
    if(l.p > r.p)
        return true;
    else if(l.p == r.p)
    {
        if(l.cnt > r.cnt)
            return true;
        else if(l.cnt == r.cnt)
            return l.id < r.id;
    }
    return false;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        a[i].id = i;    // 初始化
        cin >> m;
        int id, p;
        while(m--)
        {
            cin >> id >> p;
            a[id].p += p;
            a[id].cnt++;
            a[i].p -= p;
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
        printf("%d %.2lf\n", a[i].id, a[i].p / 100);
    return 0;
}