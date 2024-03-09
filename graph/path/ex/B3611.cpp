// 【模板】传递闭包
#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

const int N = 105;
bitset<N> g[N];
int n;

void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
        {
            if(g[i][k])
                // 以下等效于 g[i] |= g[k];
                for(int j = 1; j <= n; j++)
                    if(g[k][j])
                        g[i][j] = 1;
        }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            bool a;
            cin >> a;
            g[i][j] = a; 
        }
    }
    floyd();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << g[i][j] << ' ';
        cout << endl;
    }
    return 0;
}