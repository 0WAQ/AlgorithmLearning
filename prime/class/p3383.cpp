#include <iostream>
using namespace std;

const int N = 1e8 + 5;
int prime[N];
bool isPrime[N];
int n, q, k;

int main()
{
    std::ios::sync_with_stdio(0);

    cin >> n >> q;
    for(int i = 0; i <= n; i++)
        isPrime[i] = true;
    
    int len = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
            prime[len++] = i;
        for(int j = 0; j < len; j++)
        {
            int x = i * prime[j];
            if(x > n) break;
            isPrime[x] = false;
            if(i % prime[j] == 0)
                break;
        }
    }

    while(q--)
    {
        cin >> k;
        cout << prime[k - 1] << endl;
    }

    return 0;
}