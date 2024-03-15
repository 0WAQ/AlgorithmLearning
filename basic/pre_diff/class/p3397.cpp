#include <iostream>
using namespace std;

const int N = 1005;
int a[N][N];
int s[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    int x1, y1, x2, y2;
    while(m--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        a[x1][y1]++;
        a[x2 + 1][y1]--;
        a[x1][y2 + 1]--;
        a[x2 + 1][y2 + 1]++;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}