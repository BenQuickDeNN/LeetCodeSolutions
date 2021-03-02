#include <vector>
#include <cstdlib>
using namespace std;

class NumMatrix {
    vector<vector<int>> dp;
    size_t Y = 0, X = 0;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        Y = matrix.size();
        if (Y > 0)
        {
            X = matrix.front().size();
        }
        else
        {
            return;
        }

        dp.resize(Y, vector<int>(X));
        int _dp = 0;
        dp[0][0] = matrix[0][0];
        for (size_t x = 1; x < X; ++x)
        {
            dp[0][x] = dp[0][x - 1] + matrix[0][x];
        }
        for (size_t y = 1; y < Y; ++y)
        {
            dp[y][0] = dp[y - 1][0] + matrix[y][0];
        }
        for (size_t y = 1; y < Y; ++y)
        {
            for (size_t x = 1; x < X; ++x)
            {
                dp[y][x] = dp[y - 1][x] + dp[y][x - 1] - dp[y - 1][x - 1] + matrix[y][x];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // DP
        if (Y == 0 || X == 0)
        {
            return 0;
        }
        else if (row1 > 0 && col1 > 0)
        {
            return dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
        }
        else if (row1 == 0 && col1 > 0)
        {
            return dp[row2][col2] - dp[row2][col1 - 1];
        }
        else if (row1 > 0 && col1 == 0)
        {
            return dp[row2][col2] - dp[row1 - 1][col2];
        }
        else
        {
            return dp[row2][col2];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */