#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, t, to;
};

const int N = 55;
int g[N][N];
bool st[N][N];
int dx[4] = {0, 1, 0, -1};   //东南西北 
int dy[4] = {1, 0, -1, 0};   //0 1 2 3
int n, m, sx, sy, fx, fy, sto;
char c;
queue<node> q;

int bfs()
{
    q.push(node{sx, sy, 0, sto});
    st[sx][sy] = true;

    while(!q.empty())
    {
        node cur = q.front();
        q.pop();

        // 到达终点，返回时间
        if(cur.x == fx && cur.y == fy)
            return cur.t;        
    
        // 向左转
        // 向右转

        // 走的步数
        for(int i = 1; i <= 3; i++)
        {
            
        }
    }

   return -1; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];
    cin >> sx >> sy >> fx >> fy >> c;

    if(c == 'E')  sto = 0;
    else if (c == 'S') sto = 1;
    else if (c == 'W') sto = 2;
    else if (c == 'N') sto = 3;

    cout << bfs() << endl;
    return 0;
}