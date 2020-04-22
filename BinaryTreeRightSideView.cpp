// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，
// 返回从右侧所能看到的节点值

#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
    void search(TreeNode* p, int& max_depth, int curr_depth, vector<int>& result)
    {
        if (curr_depth > max_depth)
        {
            max_depth = curr_depth;
            result.push_back(p->val);
        }
        if (p->right != NULL)
            search(p->right, max_depth, curr_depth + 1, result);
        if (p->left != NULL)
            search(p->left, max_depth, curr_depth + 1, result);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        /* 右向深度优先搜索，并记录最深深度 */
        int max_depth = 0;
        int curr_depth = 1;
        search(root, max_depth, curr_depth, result);
        return result;
    }
};