#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const vector<int> &_a, const vector<int> &_b)
{
    return _a.back() <= _b.back();
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 贪心算法 + 动态规划
        const size_t n = intervals.size();
        if (n == 0)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int right = intervals[0].back();
        int ans = 1;
        for (size_t i = 1; i < n; ++i)
        {
            if (intervals[i].front() >= right)
            {
                ++ans;
                right = intervals[i].back();
            }
        }
        return n - ans;
    }
};