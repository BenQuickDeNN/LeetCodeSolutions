#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动态规划
        const size_t n = prices.size();
        int buy1 = - prices[0], sell1 = 0;
        int buy2 = - prices[0], sell2 = 0;
        for (size_t i = 1; i < n; ++i)
        {
            buy1 = max(buy1, - prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};