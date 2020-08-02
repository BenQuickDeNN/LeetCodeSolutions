#include <cstdlib>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    // 左序遍历
    void traverse_left(TreeNode *node)
    {
        if (node == NULL)
            return;
        if (node->left == NULL && node->right == NULL)
            return;
        // 用左子树替换右子树
        // 自底向上
        TreeNode *p_right = node->right;
        TreeNode *p_left = node->left;
        traverse_left(p_left);
        traverse_left(p_right);
        if (p_left == NULL)
            return;
        TreeNode *tail_left = p_left;
        while (tail_left->right != NULL)
            tail_left = tail_left->right;
        tail_left->right = p_right;
        node->right = p_left;
        node->left = NULL;
    }

public:
    void flatten(TreeNode *root)
    {
        traverse_left(root);
    }
};