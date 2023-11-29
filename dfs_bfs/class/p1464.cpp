// dfs优化——记忆化搜索
#include <iostream>
using namespace std;
using LL = long long;

const int N = 25;
LL g[N][N][N];

LL w(LL a, LL b, LL c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
    {
        if (g[20][20][20] == 0)
            g[20][20][20] = w(20, 20, 20);
        return g[20][20][20];
    }
    else if (a < b && b < c)
    {
        if (g[a][b][c - 1] == 0)
            g[a][b][c - 1] = w(a, b, c - 1);

        if (g[a][b - 1][c - 1] == 0)
            g[a][b - 1][c - 1] = w(a, b - 1, c - 1);

        if (g[a][b - 1][c] == 0)
            g[a][b - 1][c] = w(a, b - 1, c);

        g[a][b][c] = g[a][b][c - 1] + g[a][b - 1][c - 1] - g[a][b - 1][c];
    }
    else
    {
        if (g[a - 1][b][c] == 0)
            g[a - 1][b][c] = w(a - 1, b, c);

        if (g[a - 1][b - 1][c] == 0)
            g[a - 1][b - 1][c] = w(a - 1, b - 1, c);

        if (g[a - 1][b][c - 1] == 0)
            g[a - 1][b][c - 1] = w(a - 1, b, c - 1);

        if (g[a - 1][b - 1][c - 1] == 0)
            g[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);

        g[a][b][c] = g[a - 1][b][c] + g[a - 1][b - 1][c] + g[a - 1][b][c - 1] - g[a - 1][b - 1][c - 1];
    }

    return g[a][b][c];
}

int main()
{
    LL a, b, c, ans;
    while (scanf("%lld %lld %lld", &a, &b, &c))
    {
        if (a == -1 && b == -1 && c == -1)
            break;
        ans = w(a, b, c);
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);
    }
    return 0;
}