#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 10010;
vector<int> g[N];
int id[N], num[N], cc[N];
bool st[N];
int n, m, t, x;

bool solve()
{
    for(int i = 1; i <= x; i++)
    {
        int u = id[i];
        for(int v = 0; v < g[u].size(); v++)
            cc[g[u][v]]--;
    }

    for(int i = 1; i <= n; i++)
        if(!st[i] && cc[i] != 0)
            return false;

    return true;
}

int main()
{
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        num[a]++, num[b]++;
    }

    cin >> t;
    while(t--)
    {
        memset(st, 0, sizeof(st));
        memcpy(cc, num, sizeof(num));

        cin >> x;
        for(int i = 1; i <= x; i++)
        {
            cin >> id[i];
            st[id[i]] = true;
        }

        if(solve()) cout << "YES\n";
        else    cout << "NO\n";
    }
    return 0;
}