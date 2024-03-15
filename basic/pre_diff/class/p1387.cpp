#include <iostream>
using namespace std;

const int N = 105;
int a[N][N], s[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    
    int ans = 0;
    int l = 1;
    while(l <= min(n, m))  // 枚举边长
    {
        for(int i = l; i <= n; i++)
        {
            for(int j = l; j <= m; j++)
            {
                if(s[i][j] - s[i - l][j] - s[i][j - l] + s[i - l][j - l] == l * l)
                    ans = max(ans, l);
            }
        }
        l++;
    }
    cout << ans << endl;
    return 0;
}