#include <iostream>
using namespace std;
using LL = long long;

const int N = 1010;
LL a[N], b[N];
LL n, c, ans = -1;

/**
 * 利用前缀和数组剪枝
*/
void dfs(LL w, int idx) // 当前总重量，当前砝码的序号
{
    if(w + b[idx] <= ans)   // 一种优化方式，个人感觉局限性很大，只有个别题可以用
        return;

    if (idx == 0)
    {
        ans = max(ans, w);
        return;
    }

    // if (ans > w)     // 根据题意，此刻w在之后选的过程中，可能会成为更大值，因此不可作为返回条件
    //     return;

    if (w + a[idx] <= c)
        dfs(w + a[idx], idx - 1);
    dfs(w, idx - 1);
}

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > c)
            break;
        b[i] = b[i - 1] + a[i];
    }
    dfs(0, n);
    cout << ans << endl;
    return 0;
}