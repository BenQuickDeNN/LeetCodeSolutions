#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int i;
        int levelCount;
        while (!nodeQueue.empty())
        {
            vector<int> line;
            res.push_back(line);
            levelCount = nodeQueue.size();
            for (i = 0; i < levelCount; i++)
            {
                res[res.size() - 1].push_back(nodeQueue.front()->val);
                if (nodeQueue.front()->left != NULL)
                    nodeQueue.push(nodeQueue.front()->left);
                if (nodeQueue.front()->right != NULL)
                    nodeQueue.push(nodeQueue.front()->right);
                nodeQueue.pop();
            }
        }
        return res;
    }
};