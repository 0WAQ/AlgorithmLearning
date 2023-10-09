#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int k = 1;
    while(1)
    {
        for(int x = 100; x > 0; x--)
        {
            if((7 * x + 21 * k) * 52 == n)
            {
                cout << x << endl << k << endl;
                return 0;
            }
        }
        k++;
    }
    return 0;
}