// AtCoder-Beginer-348-D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    int x, y, e;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

/**
 * 对于st数组的理解：根据样例3和题意，发现一个格子可以被走多次，那么bool是没有用的
 * 
 * 以下是问GPT的：
 * st数组用于记录到达每个单元格时剩余的最大能量值。
 * 这是为了避免重复访问已经以更低能量值访问过的单元格，从而优化搜索过程。
 * 
 * 具体来说，st是一个二维数组，其中st[x][y]表示达到坐标(x, y)时所剩余的最大能量。
 * 在遍历网格进行搜索时，如果某个单元格已经被以更高或相等的能量值访问过，则不需要再次访问，
 * 因为从这个单元格出发，不可能有更好的结果（即使用更少的能量到达目标）。
 * 这样做可以减少搜索空间，提高算法效率。
 * 
 * 在代码的搜索循环中，检查st[nx][ny] >= e这个条件来决定是否需要将新的位置(nx, ny)加入队列。
 * 如果当前路径的能量e不大于st[nx][ny]，意味着之前已有一条至少同样好（或更好）的路径到达了这个点，所以这条新路径就不会带来任何好处，可以跳过不考虑。
 * 
 * 这种方法是广度优先搜索（BFS）的一个变种，用于处理网格上的路径搜索问题，
 * 尤其是当路径的有效性不仅仅取决于路径的长度，还包括其他条件（如本题中的能量限制）时非常有用。
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int H, W, N;
    node s;
    cin >> H >> W;
    vector<vector<char>> A(H + 1, vector<char>(W + 1));
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 'S')
                s = {i, j, 0};
        }

    cin >> N;
    vector<vector<int>> E(H + 1, vector<int>(W + 1));
    for (int i = 1; i <= N; i++)
    {
        int r, c;
        cin >> r >> c;
        cin >> E[r][c];
    }
    s.e = E[s.x][s.y];

    auto solve = [&]() -> bool
    {
        vector<vector<int>> st(H + 1, vector<int>(W + 1));
        queue<node> q;

        q.push(s);

        while (q.size())
        {
            auto [x, y, e] = q.front();
            q.pop();

            if(A[x][y] == 'T') return true;
            if(e == 0) continue;

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 1 || nx > H || ny < 1 || ny > W || st[nx][ny] >= e || A[nx][ny] == '#') 
                    continue;

                q.push({nx, ny, max(e - 1, E[nx][ny])});
                st[nx][ny] = e;
            }
        }

        return false;
    };

    if(solve()) cout << "Yes\n";
    else    cout << "No\n";

    return 0;
}