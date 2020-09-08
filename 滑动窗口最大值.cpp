#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 使用左右横跳法
        const int n = nums.size();
        vector<int> res(n - k + 1);
        if (n == 0 || k == 0)
            return res;
        if (k == 1)
            return nums;
        vector<int> lefts(n); // 左数组
        lefts[0] = nums[0];
        vector<int> rights(n); // 右数组
        rights[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i)
        {
            // from left to right
            if (i % k == 0) 
                lefts[i] = nums[i]; // block_start
            else
                lefts[i] = max(lefts[i - 1], nums[i]);
            
            // from right to left
            const int j = n - i - 1;
            if ((j + 1) % k == 0)
                rights[j] = nums[j]; // block_end
            else
                rights[j] = max(rights[j + 1], nums[j]);
        }
        for (int i = 0; i < res.size(); ++i)
            res[i] = max(lefts[i + k - 1], rights[i]);
        return res;
    }
};