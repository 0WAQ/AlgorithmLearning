#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N][N], b[N][N], c[N][N];
int n, m, k;
int main()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int h = 0; h < k; h++)
            {
                c[i][j] += a[i][h] * b[h][j];
            }
        }
    }
    return 0;
}
