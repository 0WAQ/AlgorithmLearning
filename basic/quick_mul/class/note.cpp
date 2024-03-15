/*
    时间复杂度：O(logn)
*/

#include <iostream>
using namespace std;

const int mod = 10000007;
int n, x, ans = 1;

int main()
{
    cin >> n >> x;
    while(x)   
    {
        if(x & 1)   ans *= n % mod;   // 该位为1
        n *= n % mod;
        x >>= 1;
    }  
    cout << ans << endl;
    return 0;
}