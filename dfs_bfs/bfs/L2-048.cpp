#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int x, y;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int main()
{
    int n, m;
    cin >> n >> m;

    queue<node> q;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        g[i] = ' ' + g[i];
    }

    int cnt = 0, num = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(g[i][j] != '0')
            {
                ++cnt;

                bool f = 0;
                if(g[i][j] > '1') f = 1;

                q.push({i, j});
                g[i][j] = '0';

                while(q.size())
                {
                    auto t = q.front();
                    q.pop();

                    int x = t.x, y = t.y;

                    for(int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k], ny = y + dy[k];
                        if(nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '0')
                            continue;
                        if(g[nx][ny] > '1') f = 1;
                        q.push({nx, ny});
                        g[nx][ny] = '0';
                    }
                }

                if(f)   num++;
            }
        }
        
    cout << cnt << ' ' << num << endl;
    return 0;
}