#include <iostream>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;
    
    int ans = 0;
    while(l <= r)
    {
        int t = l;
        while(t != 0)
        {
            if(t % 10 == 2)
                ans++;
            t /= 10;
        }
        l++;
    }
    cout << ans << endl;
    return 0;
}