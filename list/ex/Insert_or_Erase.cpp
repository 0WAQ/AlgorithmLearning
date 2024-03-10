// ABC-344-E
#include <iostream>
#include <list>
#include <map>
using namespace std;

map<int, list<int>::iterator> mp;
list<int> l;
int n, q;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        l.emplace_back(a);
        auto it = l.end();
        mp[a] = --it;
    }

    cin >> q;
    while(q--)
    {
        int a, b, op;
        cin >> op;
        if(op == 1)
        {
            cin >> a >> b;
            auto it = mp[a];
            l.insert(++it, b);   // 要插在a的后面
            mp[b] = --it;   // 记录b的迭代器
        }
        else
        {
            cin >> a;
            l.erase(mp[a]);
        }
    }
    for(auto& i : l)
        cout << i << ' ';
    cout << endl;
    return 0;
}