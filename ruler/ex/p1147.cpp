#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;
    int l = 1, sum = 0;
    for(int r = 1; r <= m; r++)
    {
        sum += r;
        while(l <= r && sum > m)
        {
            sum -= l;
            l++;
        }
        if(sum == m && l != r)
            cout << l << ' ' << r << endl;
    }
    return 0;
}