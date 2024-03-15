#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
LL a[N];
int n, m;

int main()
{
    LL l = -1, r = 0, ans = -1;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = max(a[i], l);
        r += a[i];
    }

    auto check = [&](LL mid) -> bool 
    {
        int sum = 0, cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(sum + a[i] <= mid)
                sum += a[i];
            else
                sum = a[i], cnt++;          
        }
        cnt++; // !!!!!
        
        // cnt == m 段数正好相等，该mid可能是答案，应该去找更小的r=mid-1
        return cnt <= m;
    };

    while(l <= r)
    {
        LL mid = (l + r) >> 1;  // 二分答案
        if(check(mid))  // 如果cnt比m少，mid比答案大，找更小的
            ans = mid, r = mid - 1;
        else  // 否则小，找更大的
            l = mid + 1;  
    }

    cout << ans << endl;
    return 0;
}