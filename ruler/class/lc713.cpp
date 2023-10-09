#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3e4 + 5;

int numSubarrayProductLessThanK(vector<int>& a, int k)
{
    int sum = 1, ans = 0;
    int i = 0;
    for(int j = 0; j < a.size(); j++)
    {
        sum *= a[j];
        while(i <= j && sum >= k)
            sum /= a[i++];
        ans += j - i + 1;
    }
    return ans;
}

int main()
{
    int k, n;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = numSubarrayProductLessThanK(a, k);

    cout << ans << endl;

    return 0;
}