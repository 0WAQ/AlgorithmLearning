#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

using PVI = pair<vector<int>, int>;

int main()
{
    int n, m;
    map<vector<int>, int> mp;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        for(int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            v.emplace_back(t);
        }
        mp[v]++;
    }
    vector<PVI> ans;
    for(auto [v, cnt] : mp)
        ans.emplace_back(make_pair(v, cnt));

    auto cmp = [](PVI& l, PVI r) ->bool {
        if(l.second == r.second)
            for(int i = 0; i < l.first.size(); i++)
                if(l.first[i] != r.first[i])
                    return l.first[i] < r.first[i];
        return l.second > r.second;
    };

    sort(ans.begin(), ans.end(), cmp);
    
    cout << mp.size() << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].second << ' ';
        for(int j = 0; j < ans[i].first.size() - 1; j++)
            cout << ans[i].first[j] << ' ';
        cout << ans[i].first[ans[i].first.size() - 1];
        if(i + 1 != ans.size()) cout << endl;
    }
    return 0;
}