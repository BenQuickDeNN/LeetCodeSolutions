#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        /* 使用前向贪心算法 */
        int maxRight = 0; // 当前下标可达最远距离
        int end = 0; // 当前可达边界
        const int n = nums.size();
        int step = 0;
        for (int i = 0; i < n - 1; i++)
            if (maxRight >= i)
            {
                maxRight = max(maxRight, i + nums[i]);
                if (i == end)
                {
                    end = maxRight;
                    ++step;
                }
            }
        return step;
    }
};