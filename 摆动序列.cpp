#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const size_t N = nums.size();
        if (N == 0)
            return 0;
        vector<int> wiggle(N - 1, 0);
        for (size_t i = 1; i < N; ++i)
        {
            wiggle[i - 1] = nums[i] - nums[i - 1];
        }
        int ans = 1;
        int len = 1;
        const size_t NW = wiggle.size();
        for (size_t i = 1; i < NW; ++i)
        {
            if ((wiggle[i] * wiggle[i - 1]) < 0)
            {
                ++len;
            }
            else
            {
                if (len > 1)
                    ans = max(ans, len + 1);
                else
                    ans = max(ans, len);
                len = 1;
            }
        }
        if (len > 1)
            ans = max(ans, len + 1);
        else
            ans = max(ans, len);
        return ans;
    }
};