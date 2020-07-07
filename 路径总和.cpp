#include <cstdlib>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void findPath(const TreeNode* node, const int & sum, int count, bool & check)
    {
        if (check) return;
        if (node == NULL) return;
        count += node->val;
        if (count == sum && node->left == NULL && node->right == NULL)
        {
            check = true;
            return;
        }
        findPath(node->left, sum, count, check);
        findPath(node->right, sum, count, check);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // 使用深度优先搜索
        bool check = false;
        int count = 0;
        findPath(root, sum, count, check);
        return check;
    }
};