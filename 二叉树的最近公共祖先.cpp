#include <cstdlib>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* answer = NULL;
    int search(TreeNode* node, const TreeNode* p, const TreeNode* q)
    {
        if (node == NULL)
            return 0;
        const int sum = search(node->left, p, q) + search(node->right, p, q);
        if (answer != NULL)
            return 0;
        else if (node == p)
        {
            if (sum == 2)
                answer = node;
            return 1;
        }
        else if (node == q)
        {
            if (sum == 1)
                answer = node;
            return 2;
        }
        else if (sum == 3)
            answer = node;
        return sum;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* 递归遍历节点 */
        search(root, p, q);
        return answer;
    }
};