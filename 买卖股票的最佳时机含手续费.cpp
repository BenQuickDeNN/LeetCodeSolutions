#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 动态规划
        const size_t n = prices.size();
        int sell = 0, buy = -prices[0]; // sell表示不持有股票时的最大利润，buy表示持有股票时的最大利润
        for (size_t i = 1; i < n; ++i)
        {
            tie(sell, buy) = pair(max(sell, buy + prices[i] - fee), max(buy, sell - prices[i]));
        }
        return sell;
    }
};