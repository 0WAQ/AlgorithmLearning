#include <iostream>
using namespace std;

const int N = 45;
int a[N][N];

int main()
{
    int n;
    cin >> n;

    int x = 0, y = n / 2;

    a[x][y] = 1; 

    for(int i = 2; i <= n * n; i++)
    {
        int x0 = 0, y0 = 0;

        if(x == 0 && y != n - 1)
            x0 = n - 1, y0 = y + 1;
        
        else if(y == n - 1 && x != 0)
            y0 = 0, x0 = x - 1;

        else if(x == 0 && y == n - 1)
            x0 = x + 1, y0 = y;

        else if(x != 0 && y != n - 1)
            if(a[x - 1][y + 1] == 0)
                x0 = x - 1, y0 = y + 1;
            else
                x0 = x + 1, y0 = y;
        
        a[x0][y0] = i;
        x = x0, y = y0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}