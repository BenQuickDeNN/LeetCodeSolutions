#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 使用排序比较法
        vector<int> nums2(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            nums2[i] = nums[i];
        sort(nums2.begin(), nums2.end());
        int _front, _back;
        for (_front = 0; _front < nums.size(); ++_front)
            if (nums2[_front] != nums[_front])
                break;
        for (_back = nums.size() - 1; _back >= 0; --_back)
            if (nums2[_back] != nums[_back])
                break;
        if (_front >= _back)
            return 0;
        else
            return _back - _front + 1;
    }
};