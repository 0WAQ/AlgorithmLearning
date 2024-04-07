#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    while(q--)
    {
        int k;
        cin >> k;

        priority_queue<ll> q;   // 维护前i个b中最小的k个

        ll ans = 1e18, s = 0, sum = 0;
        for(int i = 1; i <= n; i++)
        {
            s += a[i]; // a的前缀和

            q.push(b[i]);
            sum += b[i];
            
            // 把最大的弹出去
            if(q.size() == k + 1)
                s -= q.top(), q.pop();

            // 找够k个
            if(q.size() == k)
                ans = min(ans, s + sum);
        }
        cout << ans << endl;
    }
    return 0;
}