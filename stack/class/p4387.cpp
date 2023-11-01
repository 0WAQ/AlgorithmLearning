#include <iostream>
#include <stack>
using namespace std;

const int N = 1e5 + 5;
int a[N];
int b[N];
stack<int> s;

int main()
{
    int n, q;
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];

        while(!s.empty())
            s.pop();   

        int j = 0;
        for(int i = 0; i < n; i++)
        {
            s.push(a[i]);
            while(s.top() == b[j])
            {
                s.pop();
                j++;
                if(s.empty())
                    break;
            }
        }

        if(s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}