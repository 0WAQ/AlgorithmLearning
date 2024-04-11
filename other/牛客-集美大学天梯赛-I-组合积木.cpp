// 括弧匹配
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    char c;
    int idx;
    node(char c, int idx) : c(c), idx(idx) {}
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<node>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i].push_back({c, i});
    }

    while (m--)
    {
        int op, x, y;
        cin >> op >> x;
        if (op == 1)
        {
            cin >> y;
            for (int i = a[x].size() - 1; i >= 0; i--)
                a[y].push_back(a[x][i]);
            a[x].clear();
        }
        else if (op == 2)
        {
            cin >> y;
            for (int i = 0; i < a[x].size(); i++)
                a[y].push_back(a[x][i]);
            a[x].clear();
        }
        else if (op == 3)  // 不能直接清空数组
        {
            vector<node> t;
            for(auto& [c, id] : a[x]) {
                if(id == x)
                    t.emplace_back(c, id);
                else
                    a[id].emplace_back(c, id);
            }
            swap(t, a[x]);
        }
    }
    
    // 2. 括号匹配
    vector<bool> st(n + 1, true);
    vector<vector<string>> ans(n + 1);
    for(int i = 1; i <= n; i++)
    {
        vector<string> t;
        t.emplace_back();

        int cnt = 0;  // ※
        for(auto& [c, id] : a[i])
        {
            if(c == '(') 
            {
                cnt++;
                t.emplace_back();
            }
            else if (c == ')') 
            {
                if(--cnt < 0) {
                    st[i] = false;
                    break;
                }
                if(!t.back().empty()) {
                    ans[i].emplace_back(t.back());
                }
                t.pop_back();
            }
            else {
                t.back() += c;
            }
        }
        if(cnt) {
            st[i] = false;
        }
        else if (!t.back().empty()) {
            ans[i].emplace_back(t.back());
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            cout << -1 << '\n';
        }
        else {
            cout << ans[i].size() << " \n"[ans[i].size() == 0];
            for(int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " \n"[j == ans[i].size() - 1];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}