#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // 动态规划
        // dp[m][n] = min(dp[m - 1][n], dp[m][n - 1]) + grid[m][n]
        // dp[0][0] = grid[0][0]
        // dp[1][0] = dp[0][0] + grid[1][0];
        // dp[0][1] = dp[0][0] + grid[0][1];
        if (grid.empty())
            return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        int sum = 0;
        if (m == 1)
            for (int i = 0; i < n; i++)
                sum += grid[0][i];
        else if (n == 1)
            for (int i = 0; i < m; i++)
                sum += grid[i][0];
        // 普通情况
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < n; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        return dp[m - 1][n - 1];
    }
};