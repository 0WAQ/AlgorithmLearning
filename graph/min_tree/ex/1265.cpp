#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 5010;
double dist[N], res;
bool st[N];
int n;

struct point {
    double x, y;
    double dist(point& p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
}p[N];

void prim()
{
    dist[1] = 0.0;
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        res += dist[t];
        st[t] = true;

        for(int j = 1; j <= n; j++)
            if(!st[j] && p[t].dist(p[j]) < dist[j])
                dist[j] = p[t].dist(p[j]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;

    for(int i = 1; i <= n; i++)
        dist[i] = 1e12 * 1.0;

    for(int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    
    prim();
    printf("%.2lf\n", res);
    return 0;
}
