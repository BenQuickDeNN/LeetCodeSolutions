#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 直接覆盖法
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != 0)
                nums[idx++] = nums[i];
        while (idx < nums.size())
            nums[idx++] = 0;
    }
};