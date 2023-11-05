#include <iostream>
using namespace std;

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

bool check(TreeNode* p, TreeNode* q)
{
    // 递归出口，递归到了叶子节点
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool checkSymmetricTree(TreeNode *root)
{
    if(!root)
        return true;
    return check(root->left, root->right);
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
    if(node)
        cout << node->val << ' ';
    if(node->left)
        print(node->left);
    if(node->right)
        print(node->right);
}

int main()
{
    ios::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
       cin >> a[i];

    TreeNode* root = build(1);
    print(root);
    cout << endl;

    if(checkSymmetricTree(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}