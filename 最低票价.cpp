#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int durations[3] = {1, 7, 30};

class Solution {
    vector<int> memo;
    /* dp(i)表示第days[i]天到最后的旅行计划的最小花费 */
    int dp(const int& i, const vector<int>& days, const vector<int>& costs)
    {
        if (i >= days.size())
            return 0;
        if (memo[i] != -1)
            return memo[i];
        memo[i] = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; k++)
        {
            while (j < days.size() && days[j] < days[i] + durations[k])
                ++j;
            memo[i] = min(memo[i], dp(j, days, costs) + costs[k]);
        }
        return memo[i];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /* 后向贪心搜索 */
        /* 从后面开始算起，尽可能少花钱 */
        memo.assign(days.size(), -1);
        return dp(0, days, costs);
    }
};