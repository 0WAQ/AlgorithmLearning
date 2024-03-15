#include <iostream>
#include <cmath>
using namespace std;

const int N = 25 * 2501 + 5;
int c[N];

int main()
{
    char ch;
    int n = 0;
    while (cin >> ch && ch != 'E')
    {
        if (ch == 'W')
            c[n++] = 1;
        else
            c[n++] = 0;
    }

    auto fun = [=](int t)
    {
        int w = 0, l = 0;
        for(int i = 0; i < n; i++)
        {
            if(c[i])    ++w;
            else        ++l;
            
            if((w >= t || l >= t ) && abs(w - l) >= 2)
            {
                cout << w << ':' << l << endl;
                w = l = 0;
            }
        }
        cout << w << ':' << l << endl;  // 如果比赛正好结束怎么办？这个会多打印一个0:0，不过可以AC
    };

    fun(11);
    cout << endl;
    fun(21);

    return 0;
}