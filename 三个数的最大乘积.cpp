#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const size_t n = nums.size();
        if (n < 3)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums.back(), nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};