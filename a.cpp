#include <iostream>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std;

queue<int> q;
const int N = 505;
int dist[N], stop[N];
bool g[N][N];
int n, m;

void bfs()
{
    dist[1] = 0;
    q.push(1);

    while(q.size())
    {
        int t = q.front();
        q.pop();

        for(int i = 1; i <= n; i++)
            if(g[t][i] && dist[i] > dist[t] + 1)
            {
                dist[i] = dist[t] + 1;
                q.push(i);
            }
    }
    if(dist[n] == 0x3f3f3f3f)   cout << "NO" << endl;
    else    cout << dist[n] - 1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dist, 0x3f, sizeof(dist));
    
    cin >> m >> n;
    string line;
    getline(cin, line); // 吃掉m和n后面的回车
    while(m--)
    {
        getline(cin, line);
        stringstream ss(line);
        int t, l = 0;
        while(ss >> t)  stop[++l] = t;  
        for(int i = 1; i <= l; i++)
            for(int j = i + 1; j <= l; j++)
                g[stop[i]][stop[j]] = 1;    // 先输入的点连接到后输入的点
    }
    bfs();
    return 0;
}