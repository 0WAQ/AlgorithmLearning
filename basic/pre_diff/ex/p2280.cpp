#include <iostream>
using namespace std;

const int N = 5e3 + 5;
int s[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y, v;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> v;
        ++x, ++y;
        s[x][y] = v;
    }
    for(int i = 1; i <= 5001; ++i)
        for(int j = 1; j <= 5001; ++j)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    int ans = -1;
    for (int i = m; i <= 5001; i++)
        for (int j = m; j <= 5001; j++)       
            ans = max(ans, s[i][j] - s[i][j - m] - s[i - m][j] + s[i - m][j - m]);
    
    cout << ans << endl;
    return 0;
}