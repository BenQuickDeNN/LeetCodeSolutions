#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 将数组中所有小于等于0的数修改为N+1
        for (int& num: nums) 
            if (num <= 0)
                num = n + 1;
        
        // 将小于等于n的元素的对应位置的元素变成负数（表示不再考虑这些数）
        for (int i = 0; i < n; ++i) 
        {
            int num = abs(nums[i]) - 1;
            if (num < n) 
                nums[num] = -abs(nums[num]);
        }

        // 返回第一个大于零的元素下标+1
        for (int i = 0; i < n; ++i) 
            if (nums[i] > 0) 
                return i + 1;
        return n + 1;
    }
};