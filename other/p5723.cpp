#include <iostream>
using namespace std;

int main()
{
    int l;
    cin >> l;

    auto prim = [=](int k) -> bool
    {
        for(int i = 2; i * i <= k; i++)
            if(k % i == 0 && k != 2)  
                return false;
        return true;
    };
    
    int sum = 0, len = 0;
    for(int i = 2; i <= l; i++)
    {
        if(prim(i) && sum + i <= l)
        {
            cout << i << endl;
            sum += i;
            len++;
        }
    }
    cout << len << endl;
    return 0;
}