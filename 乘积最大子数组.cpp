#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0], mx, mn;
        for (int i = 1; i < nums.size(); ++i) {
            mx = maxF * nums[i];
            mn = minF * nums[i];
            maxF = max(mx, max(nums[i], mn));
            minF = min(mn, min(nums[i], mx));
            ans = max(maxF, ans);
        }
        return ans;
    }
};