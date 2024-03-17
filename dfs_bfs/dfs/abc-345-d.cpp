#include <iostream>
using namespace std;

int g[10][10];
int a[7], b[7];
bool st[7];
int n, h, w;

// 铺到x，y处(从左往右，从上到下，依次铺)
void dfs(int x, int y)
{
    if (x == h)
    {
        cout << "Yes\n";
        exit(0);
    }

    if (y == w)
        dfs(x + 1, 0);

    if (g[x][y])
        dfs(x, y + 1);

    // 遍历所有瓷砖
    for (int i = 0; i < n; i++)
    {
        if (!st[i]) // 如果没被用过
        {
            st[i] = true;
            // 每块瓷砖有两种铺法
            for (int t = 0; t < 2; t++)
            {
                // 越界，跳过
                if (x + a[i] <= h && y + b[i] <= w)
                {
                    bool ok = 1;
                    // 判断这块范围内能不能铺(即没有被铺过)
                    for (int dx = 0; dx < a[i]; dx++)
                        for (int dy = 0; dy < b[i]; dy++)
                            if (g[x + dx][y + dy]) // 被铺过
                                ok = 0;

                    // 如果没有被铺过的话，就铺上
                    if (ok)
                    {
                        for (int dx = 0; dx < a[i]; dx++)
                            for (int dy = 0; dy < b[i]; dy++)
                                g[x + dx][y + dy] = 1;

                        // 继续往后铺
                        dfs(x, y + 1);

                        // 回溯
                        for (int dx = 0; dx < a[i]; dx++)
                            for (int dy = 0; dy < b[i]; dy++)
                                g[x + dx][y + dy] = 0;
                    }
                }
                swap(a[i], b[i]);
            }
            st[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> h >> w;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    dfs(0, 0);

    cout << "No\n";
    return 0;
}
