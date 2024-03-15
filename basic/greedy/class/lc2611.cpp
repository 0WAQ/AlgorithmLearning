#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        int n = reward1.size();
        int ans = 0;

        vector<int> x(n);
        for(int i = 0; i < n; i++)
        {
            ans += reward2[i];
            x[i] = reward1[i] - reward2[i];
        }
        sort(x.begin(), x.end(), greater<int>());   // 从大到小排序
        for(int i = 0; i < k; i++)
            ans += x[i];

        return ans;
    }
};

int main()
{
    vector<int> reward1, reward2;
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        reward1.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        reward2.push_back(x);
    }

    Solution s;
    int ans = s.miceAndCheese(reward1, reward2, k);
    cout << ans << endl;
    return 0;
}