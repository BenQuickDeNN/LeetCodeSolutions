#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        // 动态规划
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        int max_square_index = (int)sqrt(n) + 1;
        vector<int> square_nums(max_square_index);
        for (int i = 1; i < max_square_index; ++i)
            square_nums[i] = i * i;
        
        for (int i = 1; i <= n; ++i)
            for (int s = 1; s < max_square_index; ++s)
            {
                if (i < square_nums[s])
                    break;
                dp[i] = min(dp[i], dp[i - square_nums[s]] + 1);
            }
        return dp[n];
    }
};