// 最大食物链计数
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 5010, mod = 80112002;
int in[N], out[N], num[N];
vector<int> g[N];
queue<int> q;
int n, m, ans;

void topsort()
{
    for(int i = 1; i <= n; i++)
        if(!in[i])
        {
            q.push(i);
            num[i] = 1;
        }

    while(q.size())
    {
        int t = q.front(); 
        q.pop();

        for(int i = 0; i < g[t].size(); i++)
        {
            int j = g[t][i];
            in[j]--;
            num[j] = (num[j] + num[t]) % mod;
            if(!in[j]) 
                q.push(j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        out[a]++, in[b]++;
        g[a].push_back(b);  // a->b
    }

    topsort();

    for(int i = 1; i <= n; i++) // 可能由多个最佳消费者
        if(!out[i])
            ans = (ans + num[i]) % mod;
    cout << ans << endl;
    return 0;
}