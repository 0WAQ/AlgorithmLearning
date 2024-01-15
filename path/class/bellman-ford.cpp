/*
    Bellman-ford算法；
    时间复杂度：O(nm)
    使用场景：1.具有父权边、有边数限制
             2.可以判断是否具有负权回路（负环），不能找出环
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 510, M = 10010;
int dist[N];
int backup[N];//为了避免串联情况：https://www.acwing.com/solution/content/14088/

struct edge{
    int a, b, w;
}e[M];

int n, m, k;

/**
 * 只看算法的话，其实就是将遍历所有边的这个操作执行了n-1次
 * 但结合实际的话，那么就是Bellman-ford实现思想
*/

void Bellman_ford()
{
    //初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);  //备份

        for(int j = 1; j <= m; j++)     //遍历m条边，对每条边进行松弛操作
        {
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], backup[a] + w);      //松弛操作
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        e[i].a = a, e[i].b = b, e[i].w = w;
    }

    Bellman_ford();

    int res = dist[n];
    if(res > 0x3f3f3f3f / 2)    //因为存在负权边，所以条件不能是等于-1了
        cout << "impossible";
    else
        cout << res;
    cout << endl;

    return 0;
}

/*
    1] 重边：由于遍历了所有的边，总会遍历到较短的那一条; 
    2] 自环: 有自环就有自环啊，反正又不会死循环;
*/

/*
5 6 3
1 2 -3
2 3 2
3 4 3
4 5 2
5 1 5
1 5 5
*/
