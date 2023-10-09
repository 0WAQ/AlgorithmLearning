#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> m(n, vector<int>(n));

    int num = 1;
    int l = 0, r = n - 1, t = 0, b = n - 1;

    n = n * n;
    while(num <= n)
    {
        for(int i = l; i <= r; i++)
            m[t][i] = num++;
        t++;
        for(int i = t; i <= b; i++)
            m[i][r] = num++;
        r--;
        for(int i = r; i >= l; --i)
            m[b][i] = num++;
        b--;
        for(int i = b; i >= t; --i)
            m[i][l] = num++;
        l++;
    }
    return m;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> Matrix = generateMatrix(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << Matrix[i][j] << ' ';
        cout << endl;
    }
    return 0;
}