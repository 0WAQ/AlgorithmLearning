#include <iostream>
using namespace std;

const int N = 10;
int a[N];
int n;

// 可以有多个跳出条件，其中一个是不满足题意，另一个是满足题意（大概？）
void dfs(int last, int sum, int k)
{
    if(last == n)
        return;

    if(sum == n)
    {
        for(int i = 1; i < k; i++)
        {
            if(i == 1)  cout << a[i];
            else cout << '+' << a[i];
        }
        cout << endl;
        return;
    }

    for(int i = last; i <= n - sum; i++)
    {
        a[k] = i;
        dfs(i, sum + i, k + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    dfs(1, 0, 1);
    return 0;
}