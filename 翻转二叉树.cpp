#include <cstdlib>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode * node)
    {
        if (node == NULL)
            return;
        dfs(node->left);
        dfs(node->right);
        TreeNode * tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};