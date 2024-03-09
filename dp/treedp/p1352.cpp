// 没有上司的舞会
#include <iostream>
#include <vector>
using namespace std;

const int N = 6e3 + 5;
vector<int> g[N];
int w[N], f[N][2];
bool st[N];
int n;

// 以x为根的子树的最大值
void dfs(int x)
{   
    f[x][1] = w[x]; // x去
    f[x][0] = 0;    // x不去

    // 枚举x的孩子
    for(int i = 0; i < g[x].size(); i++)
    {
        int y = g[x][i];

        dfs(y);
        f[x][1] += f[y][0];
        f[x][0] += max(f[y][1], f[y][0]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i < n; i++)
    {
        int l, k;
        cin >> l >> k;
        st[l] = true;   // l的入度不为1就是根
        g[k].push_back(l);
    }
    
    int root;
    for(int i = 1; i <= n; i++)
        if(!st[i])
        {
            root = i;
            break;
        }
    
    dfs(root);
    cout << max(f[root][1], f[root][0]) << endl;
    return 0;
}