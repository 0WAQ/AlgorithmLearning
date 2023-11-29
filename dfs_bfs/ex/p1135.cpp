#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, t;
    node() {}
    node(int x, int t) : x(x), t(t) {}
};

const int N = 210;
int k[N], st[N], d[2] = {1, -1}; 
int n, a, b;
queue<node> q;

int bfs()
{
    // 将起点入队
    q.push(node(a, 0));
    st[a] = true;

    while(!q.empty())
    {
        // 取出队头
        node now = q.front();
        q.pop();
        
        // 题意，如果满足某一条件直接跳出
        if(now.x == b)
            return now.t;
        
        // 将队头可以到达的位置入队
        for(int i = 0; i < 2; i++)
        {
            int nx = now.x + k[now.x] * d[i];
            // 特判是否越界
            if(nx < 1 || nx > n || st[nx])
                continue;
            q.push(node(nx, now.t + 1));
            st[nx] = true;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
        cin >> k[i];
    cout << bfs() << endl;
    return 0;
}