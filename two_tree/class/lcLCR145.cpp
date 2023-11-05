#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isbool(TreeNode* p, TreeNode* q)
{

    if(p->val == q->val)
    {
        isbool(p->left, q->right);
        isbool(p->right, q->left);
    }
    else
    {
        return false;
    }
}

bool checkSymmetricTree(TreeNode *root)
{
    return isbool(root->left, root->right);
}

TreeNode* insert(TreeNode* node, int x)
{
    if(node == nullptr)
        node = new TreeNode(x);
    else if (node->left == nullptr)
        node->left = insert(node->left, x);
    else
        node->right = insert(node->right, x);
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
    int n, x;
    cin >> n;
    TreeNode* root = nullptr;
    
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }
    print(root);
    cout << endl;
    bool ans = checkSymmetricTree(root);
    cout << ans << endl;
    return 0;
}