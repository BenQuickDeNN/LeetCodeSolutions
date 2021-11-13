#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int tmp = max(res | nums[i], nums[i]);
            if (tmp > res) {
                count = 0;
                res = tmp;
            }
            if (res == tmp) {
                ++count;
            }
        }
        return count;
    }
};