#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        // 先排序
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i)
            ans = max(nums[i] - nums[i - 1], ans);
        return ans;
    }
};