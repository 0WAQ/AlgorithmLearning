#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(vector<int>& a) 
{
    int n = a.size(), ans = 0;
    stack<int> s;   // 从底到顶递减

    s.push(0);  // 第一个柱子入栈
    
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && a[s.top()] < a[i])  // 当前柱子比栈顶高，那么形成凹槽
        {
            int top = s.top();
            s.pop();
            if(!s.empty())
            {
                int ntop = s.top();
                
                int w = i - ntop - 1;
                int h = min(a[i], a[ntop]) - a[top];
                ans += w * h;
            }       
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    int n, x, ans;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    ans = trap(a);
    cout << ans << endl;
    return 0;
}