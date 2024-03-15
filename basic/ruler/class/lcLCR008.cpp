#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0, ans = nums.size() + 1, sum = 0;
    for(int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];

        while(i <= j && sum - nums[i] >= target)
            sum -= nums[i++];
        
        if(sum >= target)
            ans = min(ans, j - i + 1);
    }
    return (ans == nums.size() + 1) ? 0 : ans;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    int ans = minSubArrayLen(target, nums);
    cout << ans << endl;

    return 0;
}