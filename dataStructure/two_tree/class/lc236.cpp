#include <iostream>
#include <queue>
using namespace std;

/**
 * 数据不好输入，直接在LeetCode上运行
 */
const int N = 1010;
int a[N], n;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(!root)
        return nullptr;
    if(root == p || root == q)
        return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if(!l && !r)
        return nullptr;
    if(!l)
        return r;
    if(!r)
        return l;
    return root;
}

TreeNode* build(int i)
{
    if(i > n || a[i] == -1)
        return nullptr;
    TreeNode* node = new TreeNode;
    node->val = a[i];
    node->left = build(2 * i);
    node->right = build(2 * i + 1);
    return node;
}

void print(TreeNode* node)
{
    queue<TreeNode*> q;
    q.push(node);
    TreeNode* x;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        if(!x)
        {
            cout << x->val << ' ';
            if(!x->left)    q.push(x->left);
            if(!x->right)   q.push(x->right);
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
       cin >> a[i];

    TreeNode* root = build(1);
    TreeNode* p, *q;
    print(root);
    cout << endl;
    root = lowestCommonAncestor(root, p, q);
    print(root);
    return 0;
}