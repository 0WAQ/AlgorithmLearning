#include <iostream>
using namespace std;

const int N = 510;
int g[N][N], fa[N];
int n, m, k;

void init() {
    for(int i = 0; i < n; i++)
        fa[i] = i;
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int pa = find(x), pb = find(y);
    if(pa != pb) fa[pa] = pb;
}

int get() {
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(find(i) == i)    // 并查集的数量
            cnt++;
    return cnt;
}

int main()
{
    cin >> n >> m;

    init();
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
        merge(a, b);
    }

    // 得到一开始连通块的数量
    int cnt = get();

    cin >> k;
    for(int l = 0; l < k; l++)
    {
        int a;
        cin >> a;

        init();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i == a || j == a) // 将所有有关a的路径全部去掉
                    g[i][j] = g[j][i] = 0;
                else if(g[i][j])
                    merge(i, j);    // 重新建立并查集

        // 若该点本就是孤立点或者边缘点，那么连通块的数量要么 = cnt，要么 = cnt + 1
        // 只有当连通块的数量 > cnt + 1 时，说明该点不是边缘点或者孤立点
        int ccnt = get();   // 获得新图的连通块个数

        if(ccnt > cnt + 1)  cout << "Red Alert: City " << a << " is lost!\n";
        else cout << "City " << a << " is lost.\n";
        
        cnt = ccnt; // 更新cnt
    }
    // 只有当被攻占的城市和原本的数量相同时才能Game Over
    if(k == n)  cout << "Game Over." << endl;
    return 0;
}