// 最大子段和
#include <iostream>
using namespace std;

int a, s;
int n, ans = 1 << 31;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        s = max(s + a, a);
        if(s > ans) ans = s;
    }
    cout << ans << endl;
    return 0;
}