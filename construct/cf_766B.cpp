#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    /**
     * 假设三角形三条边分别为 a, b, c, 且 a <= b <= c
     * 那么必须满足:
     *      1. 两边之和大于第三边 ==> 最小的两边之和也大于第三边(a + b > c)
     *      2. 两边之差小于第三边 ==> 差最大的两条边也小于第三边(c - a < b 或者 c - b < a ==> a + b > c)
     * 说明1与2可以合并在一起, a + b > c
     * 
     * 若三条边不满足条件说明 a + b <= c
     *      1. a或者b太小了     ==> a和b尽可能大, 但是不能超过c
     *      2. c太大了         ==> c尽可能小, 但是不能小于b
     * 要尽可能满足以上两个条件, 只需 a b c 三边相邻
     */

    for(int i = 1; i < n - 1; i++) {
        if(a[i - 1] + a[i] > a[i + 1]) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
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