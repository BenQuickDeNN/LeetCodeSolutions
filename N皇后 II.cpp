#include <vector>
using namespace std;
class Solution {
    int R, C;
    bool isOK(const vector<vector<bool>> &plane, const int & row, const int & col)
    {
        if (row < 0 || row >= R)
            return false;
        if (col < 0 || col >= C)
            return false;
        // 扫描同一行
        for (int i = 0; i < C; ++i)
            if (plane[row][i])
                return false;
        // 扫描同一列
        for (int i = 0; i < R; ++i)
            if (plane[i][col])
                return false;
        // 扫描斜对角
        // 左上
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c)
            if (plane[r][c])
                return false;
        // 右上
        for (int r = row - 1, c = col + 1; r >= 0 && c < C; --r, ++c)
            if (plane[r][c])
                return false;
        // 左下
        for (int r = row + 1, c = col - 1; r < R && c >= 0; ++r, --c)
            if (plane[r][c])
                return false;
        // 右下
        for (int r = row + 1, c = col + 1; r < R && c < C; ++r, ++c)
            if (plane[r][c])
                return false;
        return true;
    }
    void dfs(vector<vector<bool>> &plane, const int & row, const int & col, int & count)
    {
        if (!isOK(plane, row, col))
            return;
        plane[row][col] = true;
        if (row == R - 1)
            ++count;
        else
            for (int c = 0; c < C; ++c)
                dfs(plane, row + 1, c, count);
        plane[row][col] = false;
    }
public:
    int totalNQueens(int n) {
        // 深度优先搜索
        vector<vector<bool>> plane(n, vector<bool>(n, false)); // 棋盘
        int count  = 0; // 解法数
        if (plane.empty())
            return count;
        R = plane.size();
        C = plane.back().size();
        for (int c = 0; c < C; ++c)
            dfs(plane, 0, c, count);
        return count;
    }
};