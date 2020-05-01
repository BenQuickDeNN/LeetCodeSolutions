#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int Y = matrix.size();
        if (Y < 1)
            return 0;
        const int X = matrix[0].size();
        vector<int> dp(X + 1, 0);
        int maxsqlen = 0, prev = 0, tmp;
        for (int y = 0; y < Y; y++)
            for (int x = 1; x <= X; x++)
            {
                tmp = dp[x];
                if (matrix[y][x - 1] == '1')
                {
                    dp[x] = min(min(dp[x - 1], prev), dp[x]) + 1;
                    maxsqlen = max(maxsqlen, dp[x]);
                }
                else
                    dp[x] = 0;
                prev = tmp;
            }
        return maxsqlen * maxsqlen;
    }
};