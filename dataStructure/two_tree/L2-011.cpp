// 已知二叉树的前序和中序，建树
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 35, M = 1e6;
int tree[M], mid[N], pre[N], level[N];
int n, len;

// root是当前树的根，也是前序数组的下标，start和end是当前子树的起始
void build(int root, int l, int r, int idx)
{
    if(l > r) return;

    int i = l;

    // 在中序数组中找到当前子树的根，这样i的左边是左子树，右边是右子树
    while(i < r && mid[i] != pre[root]) i++;
    tree[idx] = pre[root];
    build(root + 1, l, i - 1, idx * 2);
    build(root + i - l + 1, i + 1, r, idx * 2 + 1);
}

void print()
{
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int t = q.front();
        q.pop();

        level[++len] = tree[t];
        if(tree[2 * t + 1] != -1)   q.push(2 * t + 1);
        if(tree[2 * t] != -1)   q.push(2 * t);  
    }

    for(int i = 1; i < len; i++)
        cout << level[i] << ' ';
    cout << level[len] << endl;
}

int main()
{
    cin >> n;
    memset(tree, -1, sizeof(tree));
    for(int i = 1; i <= n; i++) cin >> mid[i];
    for(int i = 1; i <= n; i++) cin >> pre[i];

    build(1, 1, n, 1);
    print();

    return 0;
}