#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        /* 与序列中的每个数字异或即可 */
        for (int num : nums)
            res ^= num;
        return res;
    }
};