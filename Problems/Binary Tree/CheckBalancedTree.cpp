/* Max depth of a binary tree. */

#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

int maxDepthHelper(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int l = maxDepthHelper(root->left);
    if (l == -1) return -1;
    int r = maxDepthHelper(root->right);
    if (r == -1) return -1;

    if (abs(l - r) > 1)
    {
        return -1;
    }
    return 1 + std::max(l, r);
}

bool checkBalanced(TreeNode* root)
{
    int depth = maxDepthHelper(root);
    if (depth == -1)
    {
        return false;
    }
    return true;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* rl = new TreeNode(1);
    TreeNode* rr = new TreeNode(2);
    root->left = rl;
    root->right = rr;
    TreeNode* rll = new TreeNode(4);
    TreeNode* rlr = new TreeNode(5);
    root->left->left = rll;
    root->left->right = rlr;
    TreeNode* rrl = new TreeNode(7);
    TreeNode* rrr = new TreeNode(6);
    root->right->left = rrl;
    root->right->right = rrr;
    TreeNode* rrlr = new TreeNode(8);
    root->right->left->right = rrlr;
    if (checkBalanced(root))
    {
        std::cout << "This binary tree is balanced";
    }
    else
    {
        std::cout << "This binary tree is not balanced";
    }
    return 0;
}