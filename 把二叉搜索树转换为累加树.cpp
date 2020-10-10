#include <cstdlib>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int count;
    void dfs(TreeNode* node)
    {
        if (node == nullptr)
            return;
        dfs(node->right);
        count += node->val;
        node->val = count;
        dfs(node->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        count = 0;
        dfs(root);
        return root;
    }
};