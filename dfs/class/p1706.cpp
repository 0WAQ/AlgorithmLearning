#include <iostream>
#include <cstring>
using namespace std;

int a[10];
bool st[10];
int n;

void dfs(const int& x)
{
    if(x > n)
    {
        for(int i = 1; i <= n; i++)
            printf("%5d", a[i]);
        printf("\n");        
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            a[x] = i;
            st[i] = true;
            dfs(x + 1);
            st[i] = false;  // 回溯
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}