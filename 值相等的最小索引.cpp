#include <vector>

using namespace std;

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int ret = -1;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i % 10 == nums[i]) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};