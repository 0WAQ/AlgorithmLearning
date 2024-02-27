// p1616-模板题
#include <iostream>
using namespace std;
using LL = long long;

const int N = 10010, M = 1e7 + 10;
LL dp[M], w[N], v[N];
int n, m;

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++)
        for(int j = w[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[m] << endl;
    return 0;
}