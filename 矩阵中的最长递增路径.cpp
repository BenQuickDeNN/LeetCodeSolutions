#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    int Y, X;
    int dfs(const vector<vector<int>> &matrix, vector<vector<bool>> &path, vector<vector<int>> &memo, const int &y, const int &x)
    {
        bool noway = true;
        int val = matrix[y][x];
        path[y][x] = true;
        int up = 0, down = 0, left = 0, right = 0;

        if (y > 0)
            if (!path[y - 1][x])
                if (matrix[y - 1][x] > val)
                    if (memo[y - 1][x])
                        up = memo[y - 1][x];
                    else
                        up = dfs(matrix, path, memo, y - 1, x);
        if (y + 1 < Y)
            if (!path[y + 1][x])
                if (matrix[y + 1][x] > val)
                    if (memo[y + 1][x])
                        down = memo[y + 1][x];
                    else
                        down = dfs(matrix, path, memo, y + 1, x);
        if (x > 0)
            if (!path[y][x - 1])
                if (matrix[y][x - 1] > val)
                    if (memo[y][x - 1])
                        left = memo[y][x - 1];
                    else
                        left = dfs(matrix, path, memo, y, x - 1);
        if (x + 1 < X)
            if (!path[y][x + 1])
                if (matrix[y][x + 1] > val)
                    if (memo[y][x + 1])
                        right = memo[y][x + 1];
                    else
                        right = dfs(matrix, path, memo, y, x + 1);
        path[y][x] = false;
        memo[y][x] = 1 + max(max(up, down), max(left, right));
        return memo[y][x];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        // 记忆化深度优先搜索
        Y = matrix.size();
        if (Y == 0)
            return 0;
        X = matrix[0].size();
        vector<vector<bool>> path(Y, vector<bool>(X, false));
        vector<vector<int>> memo(Y, vector<int>(X, 0));
        int ret = 0;
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
                ret = max(ret, dfs(matrix, path, memo, y, x));
        return ret;
    }
};