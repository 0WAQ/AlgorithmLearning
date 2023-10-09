#include <iostream>
#include <utility>
#include <string>
using namespace std;

const int N = 1e5 + 5;
int n, m;
pair<bool , string> q[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i) // 从0开始读入和从开始读入，答案不同（一个90，另一个100）
        cin >> q[i].first >> q[i].second;

    int t = 0;
    while(--m)
    {
        int a, s;
        cin >> a >> s;
        
        if(!a)  // 向左数
        {
            if(q[t].first)  // 朝圈外，++
                t = (t + s) % n;
            else            // 朝圈内，--
                t = (t - s + n) % n;
        }
        else   // 向右数
        {
            if(q[t].first)  // 朝圈外，--
                t = (t - s + n) % n;
            else            // 朝圈内，++
                t = (t + s) % n;
        }
    }
    cout << q[t].second;
    return 0;
}