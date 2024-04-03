#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1, 0);

    auto down = [&](int i) 
    {
        int t = a[i];
        int fa = i >> 1;
        
        while(i > 1 && a[fa] > t)
        {
            a[i] = a[fa];
            i = fa;
            fa = i >> 1;
        }
        a[i] = t;
    };

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        down(i);
    }

    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++)
        mp[a[i]] = i;
    
    while(m--)
    {
        int x, y;
        cin >> x;

        string s;
        cin >> s;

        if(s[0] == 'a')
        {
            cin >> y >> s >> s;
            if(mp[x] / 2 == mp[y] / 2)  cout << "T";
            else    cout << "F";
        }
        else
        {
            cin >> s;
            if(s[0] == 'a')
            {
                cin >> s >> s >> y;
                if(mp[y] == mp[x] / 2)  cout << "T";
                else    cout << "F";
            }
            else
            {
                cin >> s;
                if(s[0] == 'r')
                {
                    if(mp[x] == 1)  cout << "T";
                    else    cout << "F";
                }
                else
                {
                    cin >> s >> y;
                    if(mp[x] == mp[y] / 2)  cout << "T";
                    else    cout << "F";
                }
            }
        }
        cout << '\n';
    }
    return 0;
}