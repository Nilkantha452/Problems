/* Do a pre-order traversal in a binary tree. */

#include <iostream>

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
     \]
    preorderTraversal(root);
    std::cout << std::endl;
    std::vector<int> ans = preorderTraversalEx(root);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}