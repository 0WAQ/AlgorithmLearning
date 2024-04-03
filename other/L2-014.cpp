#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    s.insert(0);

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        if (t < *s.rbegin())
            s.erase(*s.upper_bound(t));
        s.insert(t);
    }
    cout << s.size() - 1 << endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    deque<int> a(n);
    vector<deque<int>> q;
    for(int i = 0; i < n; i++) cin >> a[i];

    int x = n, i = 1;
    while(a.size())
    {
        int t = a.front();
        a.pop_front();

        // cout << "i: " << i << ", t = " << t << "\n";

        bool f = 0;
        for(int i = 0; i < q.size(); i++)
        {
            if(q[i].back() > t && !f)
            {
                q[i].push_back(t);
                f = true;
            }
            if(q[i].front() == x)
            {
                q[i].pop_front();
                x--;
            }
        }

        if(!f)
        {
            deque<int> l;
            l.push_back(t);
            q.push_back(l);

            if(t == x)
            {
                q[q.size() - 1].pop_front();
                x--;
            }
        }

        // cout << "This is q: \n";
        // for(int i = 0; i < q.size(); i++)
        // {
        //     for(int j = 0; j < q[i].size(); j++)
        //         cout << q[i][j] << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    cout << q.size() << endl;
    return 0;
}
*/