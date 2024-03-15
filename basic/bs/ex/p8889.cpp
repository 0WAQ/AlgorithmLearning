/*
    与 B3691 相同
*/

#include <iostream>
#include <algorithm>
using namespace std;

using LL = long long;
const int N = 5e5 + 5;
LL a[N], b[N];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%ld", &a[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%ld", &b[i]);

    sort(b + 1, b + m + 1);

    auto check_qg = [&](int k) -> bool
    {
        if(!k)
            return false;

        int l = 1, r = m;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if (b[mid] == a[k])
                return true;
            else if (b[mid] < a[k])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    };

    LL ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (check_qg(i) && !check_qg(i - 1) && i != 1 && i != n)
            ans++;
    }
    printf("%ld", ans);
    return 0;
}
