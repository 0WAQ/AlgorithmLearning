// [NOIP2001 普及组] 装箱问题
#include <iostream>
using namespace std;

const int N = 35, V = 20010;
int dp[V], w[N];
int n, v;

/**
 * 01背包问题：本题的代价与价值是相同的
 */

int main()
{
	cin >> v >> n;
	for (int i = 1; i <= n; i++)	cin >> w[i];

	for (int i = 1; i <= n; i++)
		for (int j = v; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + w[i]);

	cout << v - dp[v] << endl;;
	return 0;
}