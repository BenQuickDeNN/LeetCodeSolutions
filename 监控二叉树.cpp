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

struct Status
{
    int a, b, c;
};
class Solution {
    Status dfs(TreeNode* root)
    {
        if (root == NULL)
            return {INT_MAX / 2, 0, 0};
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return {a, b, c};
    }
public:
    int minCameraCover(TreeNode* root) {
        return dfs(root).b;
    }
};