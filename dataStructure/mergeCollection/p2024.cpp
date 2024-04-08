// p2024 NOI2001 食物链
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3 * 5e4 + 5;
vector<int> p(N);

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < N; i++)
        p[i] = i;

    int cnt = 0;
    while(q--)
    {
        int x, y, c;
        cin >> c >> x >> y;
        if(x > n || y > n) {
            cnt++;
            continue;
        }

        if(c == 1)
        {
            if(find(x) == find(y + n) || find(x + n) == find(y)) {
                cnt++;
                continue;
            }

            for(int i = 0; i < 3; i++)
                p[find(x + i * n)] = find(y + i * n);
        }
        else
        {
            if(x == y || find(x) == find(y) || find(x) == find(y + n)) {
                cnt++;
                continue;
            }
            
            // 2n -> n -> 0n -> 2n
            p[find(x + n)] = find(y);   // x吃y
            p[find(x + n + n)] = find(y + n);
            p[find(x)] = find(y + n + n);
        }
    }
    cout << cnt << endl;
    return 0;
}