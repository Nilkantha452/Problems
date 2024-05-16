/* Create a binary tree and traverse it using dfs. */

#include <iostream>
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

void inorderTraversal(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->val << " ";
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

    inorderTraversal(root);
    std::cout << std::endl;
    preorderTraversal(root);
    std::cout << std::endl;
    postorderTraversal(root);
    return 0;
}