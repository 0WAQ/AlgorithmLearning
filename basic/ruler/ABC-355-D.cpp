#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// 利用双指针, 正难则反
void solve()
{
    ll n;
    cin >> n;

    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    /**
     * 求不相交的有多少对: 对于任意的左端点, 只要有右端点小于其, 那么就不是相交的
     */

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll ans = n * (n - 1) / 2; // 最多相交数
    ll j = 0;

    // 遍历所有左端点
    for(int i = 0; i < n; i++) {
        while(j < n && r[j] < l[i])  // 计算小于该左端点的右端点个数
            j++;
        ans -= j;
    }
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