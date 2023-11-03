#include <iostream>
#include <stack>
using namespace std;

const int N = 3e6 + 5;
int a[N], f[N];
int n;

int main()
{
    ios::sync_with_stdio(0);
    stack<int> s;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = n - 1; i >= 0; i--)
    {
        // 将比当前数小的全部弹出
        while(!s.empty() && a[i] >= a[s.top()])
            s.pop();

        if(!s.empty())
            f[i] = s.top() + 1;     
        else
            f[i] = 0;
        s.push(i);
    }

    for(int i = 0; i < n; i++)
        cout << f[i] << ' ';
    cout << endl;

    return 0;
}