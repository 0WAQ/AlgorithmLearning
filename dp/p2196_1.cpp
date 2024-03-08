// [NOIP1996 提高组] 挖地雷
#include <iostream>
using namespace std;

const int N = 25;
int a[N], path[N], ans[N];
bool st[N], g[N][N];
int n, idx, maxx;

void dfs(int x, int s, int sum)
{
    auto check = [&]() -> bool {
        for(int i = 1; i <= n; i++)
            if(g[x][i] && !st[i])   // 存在能够到达的、没有走过的点
                return false;
        return true;
    };

    // 已经没有地窖可以走了
    if(check())
    {   
        if(sum > maxx)
        {
            idx = s;
            maxx = sum;
            for(int i = 0; i < idx; i++)
                ans[i] = path[i];
        }
        return;
    }

    for(int i = 1; i <= n; i++)
        if(!st[i] && g[x][i])
        {
            st[i] = true;
            path[s] = i;
            dfs(i, s + 1, sum + a[i]);
            st[i] = false;
        }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            cin >> g[i][j];
    
    // 枚举开始的位置
    for(int i = 1; i <= n; i++)
    {      st[i] = true;
        path[0] = i;
        dfs(i, 1, a[i]);
        st[i] = false;
    }

    // print
    for(int i = 0; i < idx; i++)
        cout << ans[i] << ' ';
    cout << '\n' << maxx << endl;
    return 0;
}