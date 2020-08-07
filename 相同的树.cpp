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
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr)
            return false;
        else if (q == nullptr)
            return false;
        else if (p->val != q->val)
            return false;
        else
            return dfs(p->left, q->left) && dfs(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 深度优先搜索
        return dfs(p, q);
    }
};