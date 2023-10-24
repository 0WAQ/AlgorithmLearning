#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int mid_sum(vector<int>& nums, int l, int mid, int r)
{
    int lmax = INT_MIN, rmax = INT_MIN, sum = 0;
    for(int i = mid; i >= l; --i)
    {
        sum += nums[i];
        lmax = max(lmax, sum);
    }
    sum = 0;
    for(int i = mid + 1; i <= r; ++i)
    {
        sum += nums[i];
        rmax = max(rmax, sum);
    }
    return lmax + rmax;
}

int div(vector<int>& nums, int l, int r)
{
    if(l == r)
        return nums[l];
    
    int mid = (l + r) >> 1;
    // 求左右区间
    int lsum = div(nums, l, mid);
    int rsum = div(nums, mid + 1, r);
    // 求横跨中心的
    int msum = mid_sum(nums, l, mid, r);
    return max(max(lsum, rsum), msum);
}

int maxSubArray(vector<int>& nums) 
{
    int n = nums.size(), ans = 0;
    ans = div(nums, 0, n - 1);
    return ans;
}

int main() 
{
    int n, x;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    int ans = maxSubArray(nums);
    cout << ans << endl;
    return 0;
}