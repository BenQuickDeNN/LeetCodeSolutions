#include <cstdlib>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    int dfs(TreeNode *node, bool &res)
    {
        if (!res)
            return 0;
        if (node == NULL)
            return 0;
        const int depLeft = 1 + dfs(node->left, res);
        const int depRight = 1 + dfs(node->right, res);
        if (abs(depLeft - depRight) > 1)
            res = false;
        return max(depLeft, depRight);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
};