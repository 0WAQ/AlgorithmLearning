#include <iostream>
using namespace std;

const int N = 510, INF = 1e9;
int g[N][N];
int n, m, q;

void floyd()
{
    for(int k = 1; k <= n; k++) 
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main() 
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
    
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);  // 处理重边
    }
    
    floyd();

    while(q--)
    {
        int x, y;
        cin >> x >> y;
        if(g[x][y] > INF / 2)
            cout << "no path";
        else
            cout << g[x][y];
        cout << endl;
    }
    return 0;
}