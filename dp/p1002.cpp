// 	[NOIP2002 普及组] 过河卒
#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

const int N = 25;
LL dp[N][N];
bool st[N][N];
int n, m, x, y;
int dx[] = { 0, -1, -1, 1, 1, -2, -2, 2, 2 };
int dy[] = { 0, 2, -2, 2, -2, 1, -1, 1, -1 };

/**
 *	状态定义：dp[i][j]:走到点ij时的路径条数
 *  初始状态：dp[0][0] = 0, 马到达的位置为-1;
 *  最终状态：dp[n][m]
 *  状态转移：dp[i][j]由dp[i][j - 1]和dp[i - 1][j]决定
 *			  ※使用st数组来表示马，这样以下三种转移可以统一表示
 *			  马不能到达：dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
 *			  dp[i][j-1]有马：dp[i][j] += dp[i - 1][j];
 *			  ..........有马：dp[i][j] += dp[i][j - 1];
 *			  马能够到达：dp[i][j] = -1;
*/

int main()
{
	cin >> n >> m >> x >> y;
	n++, m++, x++, y++;	// 从1，1开始计算
	for (int i = 0; i < 9; i++)
			st[x + dx[i]][y + dy[i]] = true;	// 有马
	dp[1][1] = 1;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(!st[i][j])
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
	cout << dp[n][m] << endl;
	return 0;
}