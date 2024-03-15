#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    auto check = [=](int mid) -> bool
    {   
        int sum = 0, a = 0;
        while(a + mid >= 3)
        {
            sum += mid;
            a += mid;
            mid = a / 3;
            a %= 3;
        }
        sum += mid;
        return sum < n;
    };

    int l = 1, r = n, ans = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {      
            l = mid + 1;
        }   
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}