#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxProd = INT_MIN;
        int tmpMax = 1;
        int tmpMin = 1;
        /* 动态规划法 */
        for (int i = 0; i < nums.size(); i++)
        {
            /* 如果遇上负数，那么最大最小值互换 */
            if (nums[i] < 0)
            {
                tmpMax += tmpMin;
                tmpMin = tmpMax - tmpMin;
                tmpMax -= tmpMin;
            }
            tmpMax = max(tmpMax * nums[i], nums[i]);
            tmpMin = min(tmpMin * nums[i], nums[i]);
            maxProd = max(maxProd, tmpMax);
        }
        return maxProd;
    }
};

#include <cstdio>

int main()
{
    vector<int> example = {-1, -2, -9, -6};
    Solution sol;
    fprintf(stdout, "%d\r\n", sol.maxProduct(example));
}