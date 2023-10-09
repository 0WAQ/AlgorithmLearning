/*
    开O2可以过
*/

#include <iostream>
#include <cmath>
using namespace std;

int s[11];

int main()
{
    int a, b;
    cin >> a >> b;

    auto fun1 = [&](int k) -> bool
    {
        for(int i = 2; i <= sqrt(k); i++)
        {
            if(k % i == 0)
                return false;
        }
        return true;
    };

    auto fun2 = [&](int k) -> int
    {
        int len = 0;
        while(k)
        {
            s[len++] = k % 10;
            k /= 10;
        }
        return len;
    };

    auto fun3 = [&](int k) -> bool
    {
        int len = fun2(k);
        int l = 0, r = len - 1;
        while(l <= r)
        {
            if(s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    };

    if(a % 2 == 0)
        a++;

    for(int i = a; i <= b; i += 2)
    {
        if(!fun3(i))    continue;
        if(fun1(i))
            printf("%d\n", i);
    }
    return 0;
}