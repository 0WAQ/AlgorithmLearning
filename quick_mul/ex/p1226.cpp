#include <iostream>
using namespace std;

using LL = long long;
LL n, x, p, ans = 1;

int main()
{
    cin >> n >> x >> p;
    LL a = n, b = x;

    while(x)
    {
        if(x % 2)   
            ans = (ans * n) % p;
        n = (n * n) % p;
        x /= 2;
    }

    cout << a << "^" << b << " mod " << p << "=" << ans % p << endl; 
    return 0;
}