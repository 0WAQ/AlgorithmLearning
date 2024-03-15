#include <iostream>
#include <algorithm>
using namespace std;

using LL = long long;
const int N = 1e5 + 5;
LL a[N];
int n;
LL m;

int main()
{
    LL sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a + 1, a + n + 1);
    sum -= a[1] + a[n];

    LL tot = (n - 2) * a[n];
    if(tot - sum >= m)
    {
        cout << sum + m << endl;
    }
    else
    {
        m -= tot - sum;
        LL num = m / (n - 1), s = m % (n - 1);
        cout << tot + num * (n - 2) + s - 1 << endl;
    }

    return 0;
}