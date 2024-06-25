#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
    int idx, cnt;
    
    // 对于堆的插入来说, lhs为堆中现有元素, rhs为待插入的元素
    bool operator() (const node& lhs, const node& rhs) {
        if(lhs.cnt == rhs.cnt)
            return lhs.idx > rhs.idx;
        return lhs.cnt < rhs.cnt;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    priority_queue<node, vector<node>, node> q;
    
    for(int i = 1; i <= m; i++) {
        int x; cin >> x;
        q.push({x, ++a[x]});
        cout << q.top().idx << endl;
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