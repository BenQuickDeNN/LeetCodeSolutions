#include <vector>
using namespace std;
class Solution {
    int find(const vector<int>& parent, const int & i)
    {
        // 找到节点i的最顶根节点
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }
    void joint(vector<int>& parent, const int & x, const int & y)
    {
        // 合并两个集合
        const int xset = find(parent, x);
        const int yset = find(parent, y);
        if (xset != yset)
            parent[xset] = yset;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        // use disjoint_set
        const size_t n = M.size();
        if (n == 0)
            return n;
        vector<int> parent(n, -1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (M[i][j] == 1 && i != j)
                    joint(parent, i, j);
        int count = 0;
        // 统计跟节点个数
        for (int i = 0; i < parent.size(); ++i)
            count += parent[i] == -1;
        return count;
    }
};