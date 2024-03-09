// 牛客小白月赛88-D-我不是大富翁
#include <iostream>
#include <cstring> 
using namespace std;

const int N = 5010;
int a[N];
bool f[N][N];
int n, m;

/**
 * 状态定义：f[i][j]：前i回合在j格
 * 初始状态：f[0][0] = 1，一开始就在0号格
 * 最终状态：最后一回合在0号格：f[m][0]
 * 状态转移：f[i][j] = f[i - 1][(n + j - a[i]) % n] | f[i - 1][(j + a[i]) % n];
 *          f[i][j]是从i-1回合转移来的，而第i-1回合经过顺时针或者逆时针走a[i]格到第j格
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
        a[i] %= n;
    }

    // 初始状态是必须有的
    f[0][0] = 1;    

    for(int i = 1; i <= m; i++)
        for(int j = 0; j < n; j++)
            f[i][j] = f[i - 1][(j + a[i]) % n] | f[i - 1][(n + j - a[i]) % n];
    cout << (f[m][0] ? "YES" : "NO") << endl;
    return 0;
}