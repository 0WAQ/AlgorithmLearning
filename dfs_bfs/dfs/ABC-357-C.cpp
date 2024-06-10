#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 先将其存下来，最后再打印
void solve()
{
    int n;
    cin >> n;

    vector<vector<bool>> mp(7000, vector<bool>(7000));
    auto dfs = [&](auto& dfs, int k, int x, int y) -> void
    {
        if(k == 0) {
            mp[x][y] = 1;
            return;
        }

        int a = pow(3, k - 1);
        // 向八个方向dfs
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(i == 1 && j == 1)    continue;
                else
                    dfs(dfs, k - 1, x + i * a, y + j * a);
    };

    // x、y是每一块的第一个坐标
    dfs(dfs, n, 1, 1);
    
    n = pow(3, n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            if(mp[i][j])    cout << '#';
            else    cout << '.';
        cout << endl;
    }
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