#include <iostream>
#include <string>
using namespace std;

int minimumRecolors(string blocks, int k)
{
    int l = 0, ans = k;
    for(int r = k - 1; r < blocks.size(); r++)
    {
        int res = 0;
        for (int i = l; i <= r; i++)
        {
            if (blocks[i] == 'W')
                res++;
        }
        ans = min(ans, res);
        l++;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string blocks;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        blocks.push_back(ch);
    }

    int ans = minimumRecolors(blocks, k);
    cout << ans << endl;

    return 0;
}