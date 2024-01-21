// [NOIP2002 普及组] 产生数
#include <iostream>
#include <cstring>
using namespace std;

const int N = 35;
char n[N], x[N], y[N];
bool st[99];
int k, ans, l, t;
__uint128_t s;

void output(__uint128_t x)
{
    if(x > 9) output(x / 10);
    cout << (char)(x % 10 + 48);
}

void dfs(char c)
{
    if(st[c]) return;
    st[c] = true;
    for(int i = 0; i < k; i++)
        if(x[i] == c)
            dfs(y[i]); // 可能会有多重变换，例如1变2，2变3
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    l = strlen(n);

    for(int i = 0; i < k; i++)
        cin >> x[i] >> y[i];
    
    // 最高位不能为0, 最高位单独计算
    dfs(n[0]), st[0] = 0;  // 枚举每一位有几次变换
    for(char i = '1'; i <= '9'; i++)
        t += st[i], st[i] = 0;
    s = t, t = 0;

    for(int i = 1; i < l; i++)
    {
        dfs(n[i]);
        for(char i = '0'; i <= '9'; i++)
            t += st[i], st[i] = 0;
        s *= t, t = 0;
    }
    // __uint128_t没有重载<<符号，所以输出要自己写
    output(s);
    cout << endl;
    return 0;
}