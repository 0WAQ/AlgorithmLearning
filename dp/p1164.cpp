// 小A点菜
#include <iostream>
using namespace std;

const int N = 110, M = 1010;
int dp[N][M], a[N];
int n, m;

/*
 * 状态定义：dp[i][j]：看到第i种j元时的方案数
 * 初始状态：dp[0][0] = 1;
 * 最终状态：dp[n][m];
 * 状态转移：dp[i][j] = 
*/

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)	cin >> a[i];

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (j == a[i])	dp[i][j] = dp[i - 1][j] + 1;
			else if (j < a[i]) dp[i][j] = dp[i - 1][j];
			else if (j > a[i]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
		}
	cout << dp[n][m] << endl;
	return 0;
}