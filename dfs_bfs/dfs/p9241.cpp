// 2023蓝桥杯B组省赛第四题-飞机降落
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int l, r, t;
};

bool solve()
{
    int n;
    cin >> n;

    vector<node> a(n);
    vector<bool> st(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].t;
        a[i].r += a[i].l;
    }

    bool f = false;
    auto dfs = [&](auto& dfs, int x, int now) -> void
    {
        if(x == n) {
            f = true;
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(!st[i])
            {
                if(now > a[i].r)    return;

                st[i] = true;
                if(now < a[i].l)    // now时刻飞机还没有到达
                    dfs(dfs, x + 1, a[i].l + a[i].t);
                else
                    dfs(dfs, x + 1, now + a[i].t);
                st[i] = false;
            }
        }
    };

    for(int i = 0; i < n; i++) 
    {
        st[i] = true;
        dfs(dfs, 1, a[i].l + a[i].t);
        st[i] = false;
    }

    return f;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) 
        if(solve()) cout << "YES\n"; 
        else    cout << "NO\n";

    return 0;
}