#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

const int N = 15;
int s[N], b[N];
int n, ans = INT_MAX;  

void dfs(int i, int ss, int sb)
{
    if(i > n)
    {
        // 啥都不加，不行
        if(ss == 1 && sb == 0)
            return;
        ans = min(ans, (int)fabs(ss - sb));
        return;
    }
    // 只有两种选法(加或者不加)
    // 正常情况下需要回溯ss与sb，但是ss与sb是局部变量，肯定不需要回溯的呀
    // 不需要st数组，因为不关心选没选,或者说选与没选可以从ss与sb看出来
    dfs(i + 1, ss * s[i], sb + b[i]);
    dfs(i + 1, ss, sb);
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i] >> b[i];
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}