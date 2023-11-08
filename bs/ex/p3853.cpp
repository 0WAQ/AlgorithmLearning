#include <iostream>
#include <climits>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int l, n, k;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    auto check = [&](int mid)
    {

        return true;
    };

    int l = 0, r = n - 1, ans = INT_MAX;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {

        }
        else
        {

        }
    }
    cout << ans << endl;
    return 0;
}