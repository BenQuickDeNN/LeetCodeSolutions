#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // 使用暴力法
        size_t head, p;
        int tmpSum;
        int minLen = INT_MAX;
        for (head = 0; head < nums.size(); head++)
        {
            tmpSum = 0;
            for (p = head; p < nums.size(); p++)
            {
                tmpSum += nums[p];
                if (tmpSum >= s)
                {
                    if (p - head + 1 < minLen)
                        minLen = p - head + 1;
                    break;
                }
            }
        }
        if (minLen == INT_MAX) return 0;
        else return minLen;
    }
};