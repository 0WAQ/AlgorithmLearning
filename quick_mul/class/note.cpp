/*
    时间复杂度：O(logn)
*/

#include <iostream>
using namespace std;

int n, x, ans = 1;

int main()
{
    cin >> n >> x;
    while(x)   
    {
        int t = x % 2;
        if(t)   ans *= n;   // 该位为1
        n *= n;
        x /= 2;
    }  
    cout << ans << endl;
    return 0;
}