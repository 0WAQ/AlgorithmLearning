#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 3e4 + 5;
vector<double> ans;
int a[N];
int n, m, k;

int main()
{
    cin >> n >> k >> m;

    for(int i = 0; i < n; i++)
    {
        int sum = 0, ma = 0, mi = 100;
        for(int i = 0; i < k; i++)
        {
            int v;
            cin >> v;
            sum += v;
            if(ma < v)  ma = v;
            if(mi > v)  mi = v;
        }
        sum -= ma + mi;
        ans.push_back(1.0 * sum / (k - 2));
    }
    sort(ans.begin(), ans.end(), greater());
    for(int i = m - 1; i; i--)
        printf("%.3lf ", ans[i]);
    printf("%.3lf\n", ans[0]);
    return 0;
}