#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /* 动态规划法 */
        int prevMax = 0;
        int currMax = 0;
        int tmp;
        for (int a : nums)
        {
            tmp = currMax;
            currMax = max(prevMax + a, currMax);
            prevMax = tmp;
        }
        return currMax;
    }
};