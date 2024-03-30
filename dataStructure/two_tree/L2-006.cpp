#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* l, *r;
    node(int val = 0, node* l = nullptr, node* r = nullptr) 
        : val(val), l(l), r(r) {}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> post(n + 1), mid(n + 1);
    for(int i = 1; i <= n; i++) cin >> post[i];
    for(int i = 1; i <= n; i++) cin >> mid[i];

    auto build = [&](auto self, int postl, int postr, int midl, int midr) -> node*
    {
        if(postl > postr) 
            return nullptr;

        // 后序遍历的最后一个元素是根
        node* root = new node(post[postr]);

        // 在中序遍历中找到该根
        int i;  // 找到根之前的值，都是左子树
        for(i = midl; i <= midr; i++)
            if(mid[i] == post[postr])
                break;
        
        int len = i - midl; // 左子树的长度
        // 中序遍历中，根的左边是左子树，右边是右子树
        // 后序遍历中，根节点是最后一个，它的子节点都在这之前，又有中序遍历可以得出左子节点和右子节点的数量
        root->l = self(self, postl, postl + len - 1, midl, i - 1);
        root->r = self(self, postl + len, postr - 1, i + 1, midr);

        return root;
    };

    node* root = build(build, 1, n, 1, n);

    vector<int> ans;
    auto bfs = [&]()
    {
        queue<node*> q;
        q.push(root);

        while(q.size())
        {
            node* t = q.front();
            q.pop();

            ans.push_back(t->val);

            if(t->l)    q.push(t->l);
            if(t->r)    q.push(t->r);
        }
    };

    bfs();
    for(int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ' ';
    cout << ans[ans.size() - 1] << '\n';
    return 0;
}