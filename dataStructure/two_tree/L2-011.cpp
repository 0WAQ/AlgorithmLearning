// 已知二叉树的前序和中序遍历还原树 && 镜像二叉树的层序遍历
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6;

void solve()
{
    int n;
    cin >> n;

    vector<int> mid(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i++) cin >> mid[i];
    for(int i = 1; i <= n; i++) cin >> pre[i];

    // 建树
    vector<int> tree(N, -1);    // tree中存储的真实的树，需要的大小为1e6
    // 当前子树的根节点是root（在前序中），l、r是当前子树的起始位置与结束位置（在中序中）
    auto build = [&](auto& build, int root, int l, int r, int x) -> void {
        if(l > r)   return;

        // i是root在中序数组中的位置，从l ~ i - 1是左子树，i + 1 ~ r是右子树
        int i = l;
        while(i < r && pre[root] != mid[i])
            i++;
        
        tree[x] = pre[root];

        /**
         * 该子树的左子树：
         * 子树的根节点是root + 1，因为是前序遍历
        */
        build(build, root + 1, l, i - 1, x * 2);

        /**
         * 该子树的右子树：
         * 左子树的长度是 (i - 1) - l + 1 = i - l
         * 右子树的根是（在前序中）是 root + (i - l) + 1
        */
        build(build, root + i - l + 1, i + 1, r, x * 2 + 1);
    };
    build(build, 1, 1, n, 1);

    // 层序遍历的反转（只需要将右孩子先于左孩子入队即可）
    vector<int> level;
    auto print = [&]() -> void {

        queue<int> q;
        q.push(1);

        while(!q.empty())
        {
            int t = q.front();
            q.pop();

            level.emplace_back(tree[t]);
            
            // 将左右孩子反转入队
            int l = 2 * t, r = l + 1;
            if(tree[r] != -1) q.push(r);
            if(tree[l] != -1) q.push(l); 
        }

        for(int i = 0; i < level.size(); i++)
            cout << level[i] << " \n"[i == level.size() - 1];
    };
    print();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}