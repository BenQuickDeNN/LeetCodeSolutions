#include <cstdlib>
#include <vector>
#include <stack>
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
    /**
     * @param inorder 中序遍历
     * @param postorder 后序遍历
     */
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 使用迭代法
        if (postorder.size() == 0)
            return nullptr;
        auto root = new TreeNode(postorder.back());
        auto s = stack<TreeNode*>();
        s.push(root);
        int inorderIdx = inorder.size() - 1;
        for (int i = postorder.size() - 2; i>= 0; --i)
        {
            const int & postorderVal = postorder[i];
            auto node = s.top();
            if (node->val != inorder[inorderIdx])
            {
                node->right = new TreeNode(postorderVal);
                s.push(node->right);
            }
            else
            {
                while (!s.empty() && s.top()->val == inorder[inorderIdx])
                {
                    node = s.top();
                    s.pop();
                    --inorderIdx;
                }
                node->left = new TreeNode(postorderVal);
                s.push(node->left);
            }
        }
        return root;
    }
};