// p1775
#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int dp[N][N], a[N];
int n;

int main()
{
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        dp[i][i] = 0;
    }

    for(int len = 1; len <= n; len++)
        for(int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
        }

    cout << dp[1][n] << endl;
    return 0;
}