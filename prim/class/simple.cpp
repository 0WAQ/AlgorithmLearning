
/*
    输出数字n前的所有素数
    时间复杂度：O(n)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    auto isPrim = [&](int k) -> bool
    {
        if(k < 2) return false;
        for(int i = 2; i < sqrt(k); i++)
            if (k % i == 0)
                return false;
        return true;
    };

    for(int i = 1; i <= n; i++)
    {
        if(isPrim(i))
            cout << i << ' ';
    }
    cout << endl;
    return 0;
}