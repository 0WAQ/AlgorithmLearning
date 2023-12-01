#include <iostream>
#include <climits>
using namespace std;

const int N = 25;
int s[5];
int a[5][21];
int l, r, t;

// 可以将l、r作为dfs的参数，具体方法参考p2036

void dfs(int x, int y)  // x科y题
{
    if(y > s[x])    // 该科题全部做完了
    {
        t = min(t, max(l, r));
        return;
    }

    /*
        将每道题分别给左右，找最小时间
    */

    l += a[x][y];
    dfs(x, y + 1);
    l -= a[x][y];

    r += a[x][y];
    dfs(x, y + 1);
    r -= a[x][y];
}

int main()
{
    int ans = 0;
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    for(int i = 1; i <= 4; i++)
    {
        l = r = 0;
        t = INT_MAX;
        for(int j = 1; j <= s[i]; j++)
            cin >> a[i][j];
        dfs(i, 1);  // 第i科的第一题
        ans += t;
    }

    cout << ans << endl;
    return 0;
}