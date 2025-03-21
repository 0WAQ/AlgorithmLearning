/*
    时间复杂度：O(n)
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;
int prime[N];
bool isPrime[N];
int n;

int main()
{
    cin >> n;

    for(int i = 0; i <= n; i++)
        isPrime[i] = 1;

    int len = 0;
    for(int i = 2; i <= n; i++)
    {
        // 缺陷：一个非质数可能会被筛到多次
        if(isPrime[i])   // 如果 i 是质数
        {
            prime[len++] = i;   // 将i放入prime数组
            for(int j = 2 * i; j <= n; j += i)  // i的倍数不是质数
                isPrime[j] = 0;
        }
    }

    for(int i = 0; i < len; i++)
        cout << prime[i] << ' ';
    cout << endl;
    return 0;
}