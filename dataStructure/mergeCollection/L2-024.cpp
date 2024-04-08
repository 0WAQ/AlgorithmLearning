#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p(1e4 + 10);
void init() {
    for(int i = 0; i < 1e4 + 10; i++)
        p[i] = i;
}
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
    int n;
    cin >> n;

    init();
    set<int> st;

    for(int i = 0; i < n; i++)
    {
        int k, a, b;
        cin >> k;

        cin >> a;
        st.insert(a);
        k--;

        while(k--)
        {
            cin >> b;
            p[find(b)] = find(a);
            st.insert(b);
        }
    }

    int cnt = 0;
    for(int i = 1; i <= st.size(); i++)
        if(p[i] == i)   
        cnt++;
    cout << st.size() << ' ' << cnt << '\n';

    int q;
    cin >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b))  cout << "Y\n";
        else    cout << "N\n";
    }
    return 0;
}