#include <iostream>
using namespace std;

const int N = 5e4 + 5;
int s[N];
int f[7], l[7];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = (s[i - 1] + s[i]) % 7;
    }

    int ans = -1, t = 0;

    while (t <= 6)
    {
        int i = 1, j = n;
        while (s[i] != t && i <= n) // s[i] = a[1] + ... + a[i - 1] + a[i]
            i++;
        while (s[j] != t && j >= 1) // s[j] = a[1] + ... + a[i - 1] + a[i] + a[i + 1] ... + a[j]
            j--;
        
        // 当模为0的时候，不仅与其它值有同样的意思，并且它代表：从a[0]到a[i]的和为7的倍数
        // 所以当模为0的时候，不可以是右边的0减去左边的0，而是右边的0及其左边的所有数
        if (t == 0) //为什么要特判？？？
            i = 0;

        ans = max(ans, j - i);  // j - (i + 1) + 1
        t++;
    }

    cout << ans << endl;
    return 0;
}


/*
    // 第二个版本

#include <iostream>
using namespace std;

const int N = 5e4 + 5;
int s[N];
int f[7], l[7];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = (s[i - 1] + s[i]) % 7;
    }

    int ans = 0;
    for(int i = n; i >= 1; i--)
        f[s[i]] = i;

    f[0] = 0;
    for(int i = 1; i <= n; i++)
        l[s[i]] = i;

    for(int i = 0; i <= 6; i++)
        ans = max(ans, l[i] - f[i]);

    cout << ans << endl;
    return 0;
}

*/