#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[N];
int n, c;

int main()
{
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    auto check = [=](int mid)
    {
        int i = 1, j = 1, sum = 1;
        while(j <= n)
        {
            if(a[j] - a[i] < mid)
                j++;
            else
               i = j, sum++; 
        }
        return sum >= c;
    };

    int l = 1, r = a[n], ans = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}