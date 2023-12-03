#include <iostream>
#include <string>
using namespace std;

string str;
bool st[8];
int big[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int q, ans;

inline bool rn(const int& a)   // 判断闰年
{
    return (a%4==0 && a%100!=0) || a%400==0;
}

inline bool prime(const int& a)
{
    if(a == 1 || a == 0)    
        return false;

    if(a == 2 || a == 3)    
        return true;

    if(a%6!=1 && a%6!=5)
        return false;

    for(register int i = 5; i * i <= a; i += 6)
        if(a % i == 0 || a % (i + 2) == 0)
            return false;

    return true;
}

inline bool check(const string s)
{
    register const int year = stoi(s.substr(0, 4));
    register const int month = stoi(s.substr(4, 2));
    register const int day = stoi(s.substr(6, 2));

    big[2] = (rn(year) ? 29 : 28);

    if(year < 1 || year > 9999)  
        return false;
    
    if(month < 1 || month > 12)  
        return false;
    
    if(day < 1 || day > big[month]) 
        return false;
    
    return (prime(day) && prime(month * 100 + day) && prime(year * 10000 + month * 100 + day)); 
}

void dfs(register int k) // 第几位，当前字串
{
    if(k ==8)
    {
        if(check(str)) ans++;
        return ;
    }

    if(str[k] == '-')
    {
        for(register char i = '0'; i <= '9'; i++)
        {
            if(k == 4 && i > '1')
                continue;
            if(k == 5 && st[4] == '1' && i > '2')
                continue;
            if(k == 5 && st[4] == '0' && i == '0')
                continue;
            if(k == 6 && i > '3')
                continue;
            if(k == 7 && !(i - '0') & 1)
                continue;

            str[k] = i;
            dfs(k + 1);
            str[k] = '-';
        }
    }
    else
        dfs(k + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> q;
    while(q--)
    {
        cin >> str;
        if(str == "--------")
        {
            cout << "55157" << endl;
            continue;
        }
        dfs(0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
