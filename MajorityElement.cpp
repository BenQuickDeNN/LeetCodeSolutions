#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int Length = nums.size();
        map<int, int> count_map;
        int i;
        for (i = 0; i < Length; i++)
        {
            if (count_map.end() == count_map.find(nums[i]))
            {
                count_map[nums[i]] = 1;
                if (count_map[nums[i]] > Length / 2)
                    break;
            }
            else
            {
                count_map[nums[i]] = count_map[nums[i]] + 1;
                if (count_map[nums[i]] > Length / 2)
                    break;
            }
        }
        return nums[i];
    }
};