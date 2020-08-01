#include <vector>
#include <climits>
#include <queue>
using namespace std;
class Solution {
public:
    /**
    * 给定 k 个列表，需要找到最小区间，使得每个列表都至少有一个数在该区间中。
    * 该问题可以转化为，从 k 个列表中各取一个数，使得这 k 个数中的最大值与最小值的差最小。
    */
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // 使用最小堆
        int rangeLeft = 0, rangeRight = INT_MAX;
        int size = nums.size();
        vector<int> next(size);

        // 比较方法
        auto cmp = [&](const int& u, const int& v)
        {
            return nums[u][next[u]] > nums[v][next[v]];
        };

        // 堆
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minVal = 0, maxVal = INT_MIN;
        for (int i = 0; i < size; ++i)
        {
            pq.emplace(i);
            maxVal = max(maxVal,nums[i][0]);
        }

        // 挑选最小的区间
        while (true)
        {
            int row = pq.top();
            pq.pop();
            minVal = nums[row][next[row]];
            if (maxVal - minVal < rangeRight - rangeLeft)
            {
                rangeLeft = minVal;
                rangeRight = maxVal;
            }
            if (next[row] == nums[row].size() - 1)
                break;
            ++next[row];
            maxVal = max(maxVal, nums[row][next[row]]);
            pq.emplace(row);
        }
        return {rangeLeft, rangeRight};
    }
};