/*
    当前缀和数组从0开始时的做法
*/

#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{   
    for(int i = 1; i < nums.size(); ++i)
        nums[i] += nums[i - 1];

    int l = 1;
    while(l <= nums.size())
    {
        for(int i = l; i < nums.size(); ++i)
            if(nums[i] - nums[i - l] >= target)
                return l;
        l++;
    }
    if(nums[l - 2] >= target)
        return l - 1;
    return 0;
}      

int main()
{
    int target, n;
    cin >> n >> target;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int l = minSubArrayLen(target, nums);
    cout << l << endl;

    return 0;
}