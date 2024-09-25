#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * 可以从 permutation 这个单词和数据范围判断出是dfs
 */

void solve()
{
    int n, mg, mh;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1)),
                        h(n + 1, vector<int>(n + 1)),
                        A(n + 1, vector<int>(n + 1));

    cin >> mg;
    while(mg--) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    cin >> mh;
    while(mh--) {
        int u, v;
        cin >> u >> v;
        h[u][v] = h[v][u] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    vector<int> st(n + 1, false);
    vector<int> rel(n + 1, -1);
    ll ans = 1e18;

    auto dfs = [&](auto&& dfs, int x) -> void {
        if(x > n) {
            ll cost = 0;

            // i, j 对应 rel[i], rel[j]
            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    if(g[rel[i]][rel[j]] != h[i][j]) {
                        cost += A[i][j];
                    }
                }
            }

            ans = min(ans, cost);
            return;
        }

        // 枚举对应关系
        for(int i = 1; i <= n; i++) {
            if(st[i]) continue;

            st[i] = true;
            rel[x] = i;     // 点x对应点i
            dfs(dfs, x + 1);
            st[i] = false;
        }

    };

    dfs(dfs, 1);
    cout << ans << endl;
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