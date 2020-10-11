#include <cstdlib>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int ans;
    int dfs(TreeNode* node)
    {
        if (node == NULL)
            return -1;
        const int l = 1 + dfs(node->left);
        const int r = 1 + dfs(node->right);
        ans = max(ans, l + r);
        return max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // 深度优先搜索
        ans = 0;
        dfs(root);
        return ans;
    }
};