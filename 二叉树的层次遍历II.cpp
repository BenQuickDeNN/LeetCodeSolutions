#include <cstdlib>
#include <vector>
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
    void dfs(TreeNode * node, vector<vector<int>> & res, const int & depth)
    {
        if (node == NULL)
            return;
        while (res.size() <= depth)
            res.emplace_back(vector<int>());
        dfs(node->left, res, depth + 1);
        dfs(node->right, res, depth + 1);
        res[depth].push_back(node->val);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};