/* Do an preorder traversal in a binary tree. */

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

std::vector<int> preorderTraversalEx(TreeNode* root)
{
    std::vector<int> ans;
    std::stack<TreeNode*> st;
    while (1)
    {
        if (root != nullptr)
        {
            ans.push_back(root->val);
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.size() == 0)
            {
                break;
            }
            TreeNode* node = st.top();
            st.pop();
            root = node->right;
        }
    }
    return ans;
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

    preorderTraversal(root);
    std::cout << std::endl;
    std::vector<int> ans = preorderTraversalEx(root);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}