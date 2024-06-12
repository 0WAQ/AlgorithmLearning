#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    bool flag[200] = {0};
    int n = s.size();
    int l = 0, ans = 0;
    for(int r = 0; r < n; r++)  // pwwkew
    {
        while(l <= r && flag[s[r]])
        {
            flag[s[l]] = 0;
            l++;
        }
        flag[s[r]] = 1;
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    
    return 0;
}