#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> asteroidCollision(vector<int> &a)
{
    vector<int> ans;
    for(int i = 0; i < a.size(); i++)
    {
        if(ans.empty() || a[i] > 0)
            ans.push_back(a[i]);
        else
        {
            // 只有栈顶行星往右，当前行星往左才能碰撞
            while(!ans.empty() && ans.back() > 0 && a[i] < 0 && ans.back() < -a[i]) // 如果栈顶小于a[i]，那么出栈
                ans.pop_back();                     // a[i] < 0 可以去掉
            
            if(ans.empty() || ans.back() < 0)   // 如果当前栈空或者和 a[i] 的方向一样，那么 a[i] 直接入栈
                ans.push_back(a[i]);
            // 接下来，此栈顶一定和 a[i] 方向相反，并且 栈顶 >= a[i]
            else if (ans.back() == -a[i])   // 如果大小相等，两者都没
                ans.pop_back();
            // 如果栈顶 > a[i], 不用管，a[i] 会被撞没
        }
    }
    return ans;
}

int main()
{
    vector<int> a;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    vector<int> ans = asteroidCollision(a);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}