// 完全二叉树的层序遍历
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5 + 10;
int a[N], ans[N];
int n, k;

// 这个过程其实就是模拟了二叉树的后序遍历
void dfs(int x)
{
    if(x > n)   return;

    dfs(2 * x);
    dfs(2 * x + 1);
    ans[x] = a[++k];    // 本来应该打印a[++k]的
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1);
    for(int i = 1; i < n; i++)
        cout << ans[i] << ' ';
    cout << ans[n] << endl;
    return 0;
}