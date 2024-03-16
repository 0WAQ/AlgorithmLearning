#include <iostream>
#include <map>
#include <set>
using namespace std;

set<string> s; // 关注列表
map<string, int> mp;
int n, m, sum;
double avr;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string str;
        int a;
        cin >> str >> a;
        mp[str] = a;
        sum += a;
    }
    avr = sum / m;

    bool f = false;
    for(auto [str, a] : mp)
    {
        if(!s.count(str) && 1.0 * a > avr)
        {
            cout << str << '\n';
            f = true;
        }
    }
    if(!f)
        cout << "Bing Mei You" << endl;
    return 0;
}