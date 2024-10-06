#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    ll m;
    cin >> n >> m;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](ll mid) -> bool {
        ll s = 0;
        for(int i = 0; i < n; i++) {
            s += min(a[i], mid);
        }

        // 根据题意, 当 s == m 时, 说明当前补贴 mid 有可能是最终答案, 
        //          当 s < m 时, 说明 mid 小了, 答案在右边, 并且当前mid可能是最终答案
        //          当 s > m 时, 说明 mid 大了, 答案在左边, 并且当前mid不可能是最终答案, 因为超过了限制
        // 所以必须要将 s == mid 这种情况划给右边, 使区间划分为 [l, mid - 1] 与 [mid, r]
        
        
        // 此时, 返回条件可以是 s >= m, 也可以是 s < m
        return s >= m;
    };

    ll l = 0, r = 1e14;
    while(l < r) {
        ll mid = l + (r - l + 1 >> 1);
        if(check(mid)) {
            l = mid;    // 选择了 s >= m, 那么check为true时, 答案应该在右边这个区间
                        // 但在计算mid时, 若没有 +1, 代表向下取整, 那么计算出来的mid就会落在左区间
                        // 此时再将mid赋值给l就会造成无限循环(因为l本身就在左区间, 你将mid赋值给它, 还在左区间)
        }
        else {
            r = mid - 1;
        }
    }

    if(r == 1e14) {
        cout << "infinite\n";
    }
    else {
        cout << l << "\n";
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