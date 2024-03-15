#include <iostream>
using namespace std;

const int N = 10005;
int a[N], b[N], x[N], y[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> x[i] >> y[i];

    int sx, sy;
    cin >> sx >> sy;

    int ans = -1;
    for(int i = n; i >= 1; --i)
    {
        if(sx >= a[i] && sx <= a[i] + x[i] && sy >= b[i] && sy <= b[i] + y[i])
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}