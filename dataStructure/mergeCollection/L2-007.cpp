#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int N = 1e4 + 5;

struct answer
{
    int id, num, cnt;
    double area;
};

struct Node {
    int num;
    double area;
}a[N];

int fa[N];
bool st[N];
set<int> s;
map<int, answer> mp;
int n, cnt;

void init()
{
    for(int i = 0; i < N; i++)
        fa[i] = i;
}

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    int pa = find(x), pb = find(y);
    
    // 将编号小的作为祖宗
    if(pa > pb)
        fa[pa] = pb;
    else if(pa < pb)
        fa[pb] = pa;
}

bool cmp(answer& l, answer& r)
{
    if(l.area / l.cnt == r.area / r.cnt)  
        return l.id < r.id;
    return l.area / l.cnt > r.area / r.cnt;
}

int main()
{
    cin >> n;
    init();
    for(int i = 0; i < n; i++)
    {
        int id, f, m, k;
        cin >> id >> f >> m >> k;

        s.insert(id);
        if(f != -1) merge(id, f), s.insert(f);
        if(m != -1) merge(id, m), s.insert(m);

        for(int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            merge(id, v);
            s.insert(v);
        }
        cin >> a[id].num >> a[id].area;
    }

    // 遍历所有编号
    for(auto i : s)
    {
        int zz = find(i);
        if(!st[zz])
        {
            cnt++; // 家庭个数
            st[zz] = true;
        }
        mp[zz].id = zz;
        mp[zz].num += a[i].num;
        mp[zz].area += a[i].area;
        mp[zz].cnt++;  // 家庭人口
    }
    
    vector<answer> ans;
    for(auto i : mp)
        ans.push_back(i.second);

    cout << cnt << endl;
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].cnt, 
                        1.0 * ans[i].num / ans[i].cnt, 1.0 * ans[i].area / ans[i].cnt);
    return 0;
}