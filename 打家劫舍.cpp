#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) 
            return 0;
        const int size = nums.size();
        if (size == 1)
            return nums[0];
        /* 采用滚动数组 */
        int first = nums[0], second = max(nums[0], nums[1]), temp;
        for (int i = 2; i < size; i++) {
            temp = first + nums[i];
            first = second;
            if (temp > second)
                second = temp;
        }
        return second;
    }
};