#include <cstdlib>
#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int dfs(const TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return 1 + max(dfs(node->left), dfs(node->right));
    }

public:
    int maxDepth(TreeNode *root)
    {
        // 深度优先搜索
        return dfs(root);
    }
};