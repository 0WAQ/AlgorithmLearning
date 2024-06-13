// AtCoder Magics
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int A, C;
    int idx;

    bool operator < (const node& rhs) {
        return this->A < rhs.A;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<node> v(n + 1);
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        cin >> v[i].A >> v[i].C;
        v[i].idx = i;
    }
    sort(v.begin(), v.end());

    // 最后一个元素一定在集合中, 因为其A是最大的, 只有更小的A会被淘汰
    ans.push_back(v.back().idx);
    int mi = v.back().C; // 从由到i,最小的C

    // 本质是寻找逆序对
    for(int i = n - 1; i >= 1; i--)
    {
        if(v[i].C < mi) // 当前C比mi还小, 是递减的 
            ans.push_back(v[i].idx);
        
        // 让基准为更小的C
        mi = min(mi, v[i].C);
    }
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
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