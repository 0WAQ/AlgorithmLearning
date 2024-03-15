#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

struct s
{
    int a, b;
};

int n, m, q;
s a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].b;
        a[i].a = i;
    }

    sort(a + 1, a + n + 1, [=](s x, s y) -> bool { return x.b < y.b; });

    cin >> q;
    while (q--)
    {
        cin >> m;
        int l = 1, r = n, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if(a[mid].b == m)
            {
                ans = a[mid].a;
                break;
            }
            if(a[mid].b < m)
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}