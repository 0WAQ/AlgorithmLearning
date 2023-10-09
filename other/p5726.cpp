#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double a, s = 0, mx = -1, my = 11;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        mx = max(mx, a);
        my = min(my, a);
        s += a;
    }
    double ans = (s - mx - my) / (n - 2);
    printf("%.2lf\n", ans);
    return 0;
}