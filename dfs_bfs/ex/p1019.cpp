#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int N = 25;
string g[N], c;
int st[N];
int n, ans;

int link(string s1, string s2)
{
    int l1 = s1.size(), l2 = s2.size();
    for (int i = l1 - 1; i >= 0; i--)
    {
        if (s1[i] == s2[0])
        {
            int a = i;
            for (int j = 0; j < s2.size(); j++)
            {
                if (s1[a] != s2[j])
                    break;
                a++;
            }
            if (a == s1.size())
                return a - i;
        }
    }
    return 0;
}

void dfs(string s, int l)
{
    ans = max(l, ans);
    for (int i = 0; i < n; i++)
    {
        if (st[i] >= 2)
            continue;
        int c = link(s, g[i]); // 重叠长度

        if (c > 0)
        {
            st[i]++;
            dfs(g[i], l + g[i].size() - c); // 只传当前的字符串，并不会将字符串真的
            st[i]--;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    cin >> c;
    dfs(c, 1);
    cout << ans << endl;
    
    return 0;
}