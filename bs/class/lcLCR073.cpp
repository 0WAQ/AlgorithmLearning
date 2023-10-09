/*
    与lc875相同
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    auto check = [=](int k) -> bool
    {
        int n = piles.size();
        long long s = 0;
        for (int i = 0; i < n; i++)
            s += (piles[i] + k - 1) / k;
        return s <= h;
    };

    vector<int>::iterator Max = max_element(piles.begin(), piles.end());
    int l = 1, r = *Max, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> piles;
    int n, h = 0, p;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        piles.push_back(p);
    }

    int ans = minEatingSpeed(piles, h);
    cout << ans << endl;

    return 0;
}