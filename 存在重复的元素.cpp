#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (auto & num : nums)
        {
            if (counts.find(num) != counts.end())
            {
                return true;
            }
            else
            {
                ++counts[num];
            }
        }
        return false;
    }
};