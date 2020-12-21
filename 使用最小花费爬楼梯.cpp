#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 动态规划
        const size_t n = cost.size();
        vector<int> dp(n + 1);
        for (size_t i = 2; i <= n; ++i)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};