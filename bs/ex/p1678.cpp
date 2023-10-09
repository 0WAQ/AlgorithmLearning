#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];
int n, m;

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    sort(a + 1, a + m + 1);     /// 小心！小心！！小心！！！

    long long tot = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = m, ans = 0x7fffffff;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(a[mid] < b[i])
            {
                ans = min(ans, b[i] - a[mid]);
                l = mid + 1;
            }
            else
            {   
                ans = min(ans, a[mid] - b[i]);
                r = mid - 1;
            }
        }
        tot += ans;
    }
    cout << tot << endl;
    return 0;
}