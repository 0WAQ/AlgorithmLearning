#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) 
{
    int n = s.size();
    vector<string> ans;
    unordered_map<string, int> map;
    for(int i = 0; i < n - 10; i++)
    {
        if(map[s.substr(i, 10)] == 1)
            ans.push_back(s.substr(i, 10));
        map[s.substr(i, 10)]++;
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = findRepeatedDnaSequences(s);
    int n = ans.size();
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}