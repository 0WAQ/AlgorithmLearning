#include <iostream>
#include <queue>
using namespace std;

using LL = long long;

const int N = 10010;
priority_queue<LL, vector<LL>, greater<LL>> q;   // 定义小根堆 （小的优先级高）
int n;

int main()
{
    int x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    LL ans = 0; 
    
    for(int i = 0; i < n - 1; i++)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans += x + y;
        q.push(x + y);
    }
    cout << ans << endl;
    return 0;
}