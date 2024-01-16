#include<iostream>
#include<cstring>
using namespace std;

const int N = 510;
int g[N][N]; //邻接矩阵存储稠密图
int dist[N]; //记录每个点到第一个点的距离
bool st[N]; // 记录该点的距离是不是已经被确定为最短距离

int n, m;

void Dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 0; i < n; i++)
    {
        int t = -1; 
        for(int j = 1; j <= n; j++) 
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;

        for(int j = 1; j <= n; j++) // 本质上是遍历了所有t的邻接点
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);//初始化图，因为求的是最短路
    //这里的0x3f

    while(m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);//处理重边，保留最短的一条边
    }
    Dijkstra();
    
    if(dist[n] == 0x3f3f3f3f)   //如果第n个点的路径为无穷大则代表不存在最短路径
        cout << -1;
    else
        cout << dist[n];
    cout << endl;

    return 0;
}

/*
如果是问编号a到b的最短距离该怎么改呢? （好问题）
回答： 初始化时将 dist[a]=0,以及返回时return dist[b]。

自环在朴素版dijkstra算法中是没有任何影响的，所以自环的权值是多少都可以，只要不是负数就行。
*/