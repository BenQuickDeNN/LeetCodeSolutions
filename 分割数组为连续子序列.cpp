#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // 贪心算法
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        for (auto &num : nums)
        {
            int count = countMap[num] + 1;
            countMap[num] = count;
        }
        for (auto & num : nums)
        {
            int count = countMap[num];
            if (count > 0)
            {
                int prevEndCount = endMap[num - 1];
                if (prevEndCount > 0)
                {
                    countMap[num] = count - 1;
                    endMap[num - 1] = prevEndCount - 1;
                    endMap[num] = endMap[num] + 1;
                }
                else
                {
                    int count1 = countMap[num + 1];
                    int count2 = countMap[num + 2];
                    if (count1 > 0 && count2 > 0)
                    {
                        countMap[num] = count - 1;
                        countMap[num + 1] = count1 - 1;
                        countMap[num + 2] = count2 - 1;
                        endMap[num + 2] = endMap[num + 2] + 1;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};