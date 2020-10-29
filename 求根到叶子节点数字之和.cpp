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
    void dfs(TreeNode* node, vector<int> &nums, const int &num)
    {
        if (node == NULL)
            return;
        if (node->left == NULL && node->right == NULL)
        {
            nums.emplace_back(num * 10 + node->val);
            return;
        }
        dfs(node->left, nums, num * 10 + node->val);
        dfs(node->right, nums, num * 10 + node->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        dfs(root, nums, 0);
        int sum = 0;
        for (const int &num : nums)
            sum += num;
        return sum;
    }
};