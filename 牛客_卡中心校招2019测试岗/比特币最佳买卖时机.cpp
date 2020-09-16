#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> prices;
    int price;
    while (cin >> price)
        prices.emplace_back(price);
    // 动态规划
    const int n = prices.size();
    if (n < 1)
        return 0;
    vector<int> dp(n, 0);
    int minPrice = prices.front();
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = max(prices[i] - minPrice, dp[i - 1]);
        minPrice = min(minPrice, prices[i]);
    }
    cout << dp.back() << endl;
    return 0;
}