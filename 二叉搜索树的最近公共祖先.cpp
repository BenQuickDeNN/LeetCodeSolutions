#include <cstdlib>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (p == NULL || q == NULL)
            return NULL;
        const int & valr = root->val;
        const int & valp = p->val;
        const int & valq = q->val;
        if (valr < valp && valr < valq)
            return lowestCommonAncestor(root->right, p, q);
        else if (valr > valp && valr > valq)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};