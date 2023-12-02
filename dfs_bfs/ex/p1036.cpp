#include <iostream>
using namespace std;

const int N = 25;
int a[N];
bool st[N];
int n, s, ans;

bool isPrime(int k)
{
    if(k < 2)   return false;
    for(int i = 2; i * i <= k; i++)
    {
        if(k % i == 0)
            return false;
    }
    return true;
}

void dfs(int k, int sum, int l)
{
    if(k == s)
    {
        if(isPrime(sum))
            ans++;
        return;
    }

    for(int i = l; i <= n; i++)
        dfs(k + 1, sum + a[i], i + 1);
    
}

int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}