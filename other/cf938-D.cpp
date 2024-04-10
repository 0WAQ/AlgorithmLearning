// 类似于滑动窗口
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + 1), b(m + 1);
    map<int, int> ma, mb;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i], mb[b[i]]++;

    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i <= m)
        {
            if(ma[a[i]] < mb[a[i]]) cnt++;
            ma[a[i]]++;
        }
        else
        {
            if(cnt >= k)    ans++;  // 为了统计第一次的，写在最后无法统计第一次

            if(ma[a[i]] < mb[a[i]]) cnt++;
            ma[a[i]]++;

            if(ma[a[i - m]] <= mb[a[i - m]])    cnt--;
            ma[a[i - m]]--;
        }
    }
    if(cnt >= k)    ans++; // 统计最后一次
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}