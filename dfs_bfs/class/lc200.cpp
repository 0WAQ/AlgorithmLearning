#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int n = grid.size(); 
        int m = grid[0].size();

        grid[i][j] = '0';
        if(i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if(i + 1 <  n && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if(j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if(j + 1 <  m && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }

    static int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        if(!n)  return 0;
        int m = grid[0].size();

        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    char ch;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
        
    int ans = Solution::numIslands(grid);
    cout << ans << endl;
    return 0;
}