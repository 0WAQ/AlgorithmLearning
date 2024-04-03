#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> g(n + 1, vector<bool>(n + 1)); // 是否是敌人
    vector<int> p(n + 1);   // 朋友的集合
    
    auto init = [&]() -> void {
        for(int i = 0; i <= n; i++) p[i] = i;
    };
    auto find = [&](auto& find, int x) -> int {
        return p[x] == x ? x : find(find, p[x]);
    };

    init();

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(c == 1)
        {
            int pa = find(find, a), pb = find(find, b);
            if(pa != pb) p[pb] = pa;
        }
        else
            g[a][b] = g[b][a] = 1;
    }

    while(k--)
    {
        int a, b;
        cin >> a >> b;

        int pa = find(find, a), pb = find(find, b);
        
        if(pa == pb)    // 有共同的朋友
        {
            if(!g[a][b])   cout << "No problem";
            else    cout << "OK but...";
        }
        else
        {
            if(!g[a][b])    cout << "OK";
            else    cout << "No way";
        }
        cout << "\n";
    }

    return 0;
}