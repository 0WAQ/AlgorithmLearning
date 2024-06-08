#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int s, cnt;
};

int solve()
{
    int n, m;
    cin >> m >> n;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<bool> st(1 << m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    queue<node> q;
    q.push({0, 0});
    st[0] = true;

    while(!q.empty())
    {
        auto t = q.front();
        q.pop();

        if(t.s == (1 << m) - 1)
            return t.cnt;

        // 遍历所有可能转移到的状态
        for(int i = 1; i <= n; i++)
        {
            int ss = t.s;
            // 计算转移后的状态
            for(int j = 0; j < m; j++)
            {
                // 第j个灯开时: 0 --> 1
                if(a[i][j + 1] == 1 && !(ss & (1 << j)))
                    ss |= 1 << j;   // 关
                
                // 第j个灯关时: 1 --> 0
                if(a[i][j + 1] == -1 && (ss & (1 << j)))
                    ss ^= 1 << j;
            }

            if(!st[ss]) {
                q.push({ss, t.cnt + 1});
                st[ss] = true;
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--) 
        cout << solve() << endl;

    return 0;
}