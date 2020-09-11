#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    bool isFound;
    // 深度优先搜索
    bool dfs(const vector<int>& nums, const int& target, const int& idx)
    {
        if (isFound)
            return true;
        if (target == 0)
        {
            isFound = true;
            return true;
        }
        for (int i = idx; i < nums.size(); ++i)
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            else if (target - nums[i] < 0)
                return false;
            else if (dfs(nums, target - nums[i], i + 1))
                return true;
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        // 先排序，有利于剪枝
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int& num : nums)
            sum += num;
        if (sum % 2 != 0) // 如果sum不是偶数
            return false;
        if (sum == 0)
            return true;
        isFound = false;
        return dfs(nums, sum / 2, 0);
    }
};