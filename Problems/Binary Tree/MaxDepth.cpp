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

int MaxDepthOfBinaryTree(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int l = MaxDepthOfBinaryTree(root->left);
    int r = MaxDepthOfBinaryTree(root->right);
    return 1 + std::max(l, r);
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
    std::cout << "Max depth of the tree : " << MaxDepthOfBinaryTree(root);
    return 0;
}