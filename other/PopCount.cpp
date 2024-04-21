// ABC-347-D
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int solve()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll x = 0, y = 0;
    for(int i = 0; i < 60; i++) // 从低位开始放
    {
        // 当前位为 1 那么x和y有一位是1
        if(c >> i & 1) 
        {
            // 谁剩余的1多就放在谁上，最后要保证a == b
            if(a >= b) x += (1ll << i), a--;
            else y += (1ll << i), b--;

            // 1的个数不够了
            if(a < 0 || b < 0)  return cout << -1 << endl, 0;
            // 优雅的写法,但是函数要有返回值
        }
    }


    // 放完满足 x ^ y = c 的1后，x和y中剩余的1的个数要相等
    if(a != b)  return cout << -1 << endl, 0;


    // 将剩下的1随便放（放在c的当前位为不为1的位置）
    for(int i = 0; i < 60; i++) // 这里从低位开始放
        if(!(c >> i & 1) && a) {
            x += (1ll << i), y += (1ll << i);
            a--;
        }

    // 1可能有剩余
    if(a)   cout << -1 << endl;
    else    cout << x << ' ' << y << endl;

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}