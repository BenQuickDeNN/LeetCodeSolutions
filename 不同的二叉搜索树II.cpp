#include <vector>
#include <cstdlib>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    vector<TreeNode *> genTrees(const int &start, const int &end)
    {
        if (start > end)
            return {nullptr};
        vector<TreeNode *> allTrees;
        // 枚举可行根节点
        for (int i = start; i <= end; i++)
        {
            // 获得所有可行的左子树集合
            vector<TreeNode *> leftTrees = genTrees(start, i - 1);
            // 获取所有可行的右子树集合
            vector<TreeNode *> rightTrees = genTrees(i + 1, end);
            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树
            for (auto &left : leftTrees)
                for (auto &right : rightTrees)
                {
                    TreeNode *curr = new TreeNode(i, left, right);
                    allTrees.emplace_back(curr);
                }
        }
        return allTrees;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        // 使用递归法
        // 假如根节点的值为i，name左子树值的集合为[1...i-1]，右子树节点值的集合为[i+1...n]
        // 左子树和右子树的生成是原问题的子问题

        // 空
        if (n == 0)
            return {};
        return genTrees(1, n);
    }
};