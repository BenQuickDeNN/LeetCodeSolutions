#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 缩减空间法
        const int R = matrix.size();
        if (R == 0)
            return false;
        const int C = matrix.front().size();
        // 利用排序矩阵的性质，把左下角当根节点查找
        int row = R - 1;
        int col = 0;
        while (row >= 0 && col < C)
        {
            const int & num = matrix[row][col];
            if (num > target)
                --row;
            else if (num < target)
                ++col;
            else
                return true;
        }
        return false;
    }
};