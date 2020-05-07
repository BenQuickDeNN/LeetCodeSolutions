/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <climits>
#include <vector>
#include <map>

using namespace std;

class Solution {
    const int lNull = INT_MIN;
    const int rNull = INT_MAX;
    void getDfsOrder(TreeNode* tn, vector<int>& tar)
    {
        if (!tn)
            return;
        tar.push_back(tn->val);
        if (tn->left)
            getDfsOrder(tn->left, tar);
        else
            tar.push_back(lNull);
        if (tn->right)
            getDfsOrder(tn->right, tar);
        else
            tar.push_back(rNull);
    }
    bool kmp(const vector<int>& sOrder, const vector<int>& tOrder)
    {
        const int lenS = sOrder.size();
        const int lenT = tOrder.size();
        /* 构建关于tOrder的状态表 */
        vector<int> next(tOrder.size(), -1);
        for (int i = 1, j = -1; i < lenT; ++i)
        {
            while (j != -1 && tOrder[i] != tOrder[j + 1])
                j = next[j];
            if (tOrder[i] == tOrder[j + 1])
                ++j;
            next[i] = j;
        }
        /* 匹配 */
        for (int i = 0, j = -1; i < lenS; ++i)
        {
            while (j != -1 && sOrder[i] != tOrder[j + 1])
                j = next[j];
            if (sOrder[i] == tOrder[j + 1])
                ++j;
            if (j == lenT - 1)
                return true;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        /* 在DFS序列上做串匹配 */
        /* 1. 但DFS序列的子序列不一定是子树，所以要先补空值 */
        vector<int> sOrder, tOrder;
        getDfsOrder(s, sOrder);
        getDfsOrder(t, tOrder);
        /* 使用kmp算法检验子串 */
        return kmp(sOrder, tOrder);
    }
};