/*
    该题有更好的做法
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];
int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < m; i++)  cin >> b[i];
    sort(b, b + m);

    for(int i = 0; i < n; i++)
    {
        int l = 0, r = m - 1, ans = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(b[mid] >= a[i])
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        if(a[i] == b[ans])
            cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}