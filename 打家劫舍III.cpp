#include <cstdlib>
#include <algorithm>
#include <unordered_map>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 深度优先搜索会超时
class Solution {
    int dfs(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        // 偷窃当前节点
        int gain1 = node->val;
        if (node->left != NULL)
        {
            gain1 += dfs(node->left->left);
            gain1 += dfs(node->left->right);
        }
        if (node->right != NULL)
        {
            gain1 += dfs(node->right->left);
            gain1 += dfs(node->right->right);
        }
        // 放过当前节点
        int gain2 = 0;
        gain2 += dfs(node->left);
        gain2 += dfs(node->right);
        return max(gain1, gain2);
    }
public:
    int rob(TreeNode* root) {
        // 深度优先搜索
        return dfs(root);
    }
};
*/

// 动态规划
class Solution {
public:
    // f,g 分别表示选择当前节点的最大收益和不选择当前节点的最大收益
    unordered_map <TreeNode*, int> f, g;

    void dfs(TreeNode* o) {
        if (!o) {
            return;
        }
        dfs(o->left);
        dfs(o->right);
        f[o] = o->val + g[o->left] + g[o->right];
        g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
    }

    int rob(TreeNode* o) {
        dfs(o);
        return max(f[o], g[o]);
    }
};