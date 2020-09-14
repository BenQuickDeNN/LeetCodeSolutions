#include<vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> nodeStack = {root};
        while (!nodeStack.empty())
        {
            if (nodeStack.back() == NULL)
            {
                nodeStack.pop_back();
                continue;
            }
            if (nodeStack.back()->left != NULL)
            {
                nodeStack.push_back(nodeStack.back()->left);
                nodeStack[nodeStack.size() - 2]->left = NULL;
                continue;
            }
            res.push_back(nodeStack.back()->val);
            if (nodeStack.back()->right != NULL)
            {
                nodeStack.push_back(nodeStack.back()->right);
                nodeStack[nodeStack.size() - 2] = NULL;
                continue;
            }
            nodeStack.pop_back();
        }
        return res;
    }
};