#include <cstdlib>
#include <vector>
#include <climits>
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
    void dfs(TreeNode* node, vector<int> & _arr)
    {
        if (node == NULL)
            return;
        dfs(node->left, _arr);
        _arr.push_back(node->val);
        dfs(node->right, _arr);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        // 采用中序遍历，二叉搜索树中序遍历数值大小是递增的
        vector<int> _arr;
        dfs(root, _arr);
        int _min = INT_MAX;
        for (int i = 1; i < _arr.size(); ++i)
        {
            _min = min(_min, _arr[i] - _arr[i - 1]);
        }
        return _min;
    }
};