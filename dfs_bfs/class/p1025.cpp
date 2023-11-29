// dfs优化——剪枝
#include <iostream>
using namespace std;

const int N = 10;
int n, k, ans;

void dfs(int sum, int x, int last)    // 选的顺序为不降序
{
    if(x == k)
    {
        if(sum == n)
            ans++;
        return;
    }

    // 从上一个开始选
    for(int i = last; sum + i * (k - x) <= n; i++)  // 可行性剪枝
        dfs(sum + i, x + 1, i); 
}

int main()
{
    cin >> n >> k;
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}