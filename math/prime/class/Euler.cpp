/*
    改进了埃氏筛法，分解的质数是唯一的
    时间复杂度：O(n)
*/

#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int prime[N];
bool isPrime[N];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i <= n; i++)
        isPrime[i] = true;
    
    int len = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i]) 
            prime[len++] = i;
        
        int x;
        for(int j = 0; j < len; j++) // 素数表
        {
            x = i * prime[j]; 
            if(x > n)
                break;
            isPrime[x] = false;

            if(i % prime[j] == 0)   //
                break;
        }
    }

    for(int i = 0; i < len; i++)
        cout << prime[i] << ' ';
    cout << endl;
    return 0;
}