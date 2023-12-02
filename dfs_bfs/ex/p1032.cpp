#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct node
{
    string s;
    int t;
};

const int N = 10;
string a, b;
string c[N], d[N];
map<string, bool> st; // 用map来作为记录数组
queue<node> q;
int len;

void bfs()
{
    q.push(node{a, 0});
    st[a] = true;

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        // 超过10步
        if (cur.t > 10)
        {
            cout << "NO ANSWER!" << endl;
            return;
        }

        // 遍历相邻的规则
        for (int i = 0; i < len; i++)
        {
            int pos = -1;
            while (1) // 可能不止有一个字串
            {
                string ns = cur.s;
                int nt = cur.t + 1;

                pos = cur.s.find(c[i], pos + 1);

                // 找不到这个字串, 换下一个规则
                if (pos == -1)
                    break;

                ns.replace(pos, c[i].size(), d[i]);

                // 变换成功
                if (ns == b)
                {
                    cout << nt << endl;
                    return;
                }

                // 如果下一个字符串已经加入了，跳过
                if (st[ns])
                    continue;

                q.push(node{ns, nt});
                st[ns] = true;
            }
        }
    }
    // 没有超过10步并且没有变换成功
    cout << "NO ANSWER!" << endl;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> a >> b;
    while (cin >> c[len] >> d[len]) // ！！！
        len++;
    
    bfs();
    return 0;
}