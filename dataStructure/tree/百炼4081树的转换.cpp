// http://bailian.openjudge.cn/practice/4081/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;

    int h1 = 0, h2 = 0;

    // 转换后, 某点的深度是父节点的深度加上其是父节点的第几个子节点

    int i = 0;
    auto dfs = [&](auto& dfs, int d1, int d2) -> void
    {
        h1 = max(d1, h1);
        h2 = max(d2, h2);

        int cnt = 1; // 记录该结点是父节点的第几个子节点, 一开始为1
        while(s[i])
        {
            if(s[i] == 'd') 
            {
                i++;
                dfs(dfs, d1 + 1, d2 + cnt);

                // 同层, 每多一次d, cnt++
                cnt++;
            }
            else 
            {
                i++;
                return;
            }
        }
    };
    dfs(dfs, 0, 0);
    cout << h1 << " => " << h2 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}