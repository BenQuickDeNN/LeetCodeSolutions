#include <cstdlib>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int sum)
    {
        if(root == nullptr)
            return;
        sum -= root->val;
        if(sum == 0)
            ans++;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        // 双重dfs
        if(root == nullptr)
            return ans;
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return ans;
    }
};