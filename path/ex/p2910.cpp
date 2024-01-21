// [USACO08OPEN] Clear And Present Danger S
#include <iostream>
#include <cstring>
using namespace std;

const int N = 105, M = 10010;
int g[N][N], a[M];
int n, m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    a[0] = 1, a[m + 1] = n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int ans = 0;
    for(int i = 0; i <= m; i++)
        ans += g[a[i]][a[i + 1]];
    cout << ans << endl;
    return 0;
}