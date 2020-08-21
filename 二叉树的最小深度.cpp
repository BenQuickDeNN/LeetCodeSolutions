#include <cstdlib>
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
    int mindepth = INT_MAX;
    int dfs(TreeNode* root, const int &depth)
    {
        if (root == NULL)
            return INT_MAX;
        if (depth >= mindepth)
            return depth;
        if (root->left == NULL && root->right == NULL)
            return depth + 1;
        int ret = min(dfs(root->left, depth + 1), 
            dfs(root->right, depth + 1));
        mindepth = min(mindepth, ret);
        return ret;
    }   
public:
    int minDepth(TreeNode* root) {
        // dfs, return minimal depth
        if (root == NULL)
            return 0;
        return dfs(root, 0);
    }
};