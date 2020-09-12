#include <cstdlib>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // 深度优先搜索
    void dfs(vector<pair<double, int>>& buf, TreeNode* node, const int& depth)
    {
        if (node == NULL)
            return;
        if (depth >= buf.size())
        {
            buf.resize(depth + 1);
            buf[depth].first = 0.0;
            buf[depth].second = 0;
        }
        buf[depth].first += node->val;
        ++buf[depth].second;
        dfs(buf, node->left, depth + 1);
        dfs(buf, node->right, depth + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<pair<double, int>> buf;
        dfs(buf, root, 0);
        res.resize(buf.size());
        for (int i = 0; i < buf.size(); ++i)
            res[i] = buf[i].first / (double)buf[i].second;
        return res;
    }
};