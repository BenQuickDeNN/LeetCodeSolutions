#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /* 使用动态规划——前缀和法 + 哈希表优化 */
        unordered_map<int, int> mp;
        mp[0] = 1; // 在开始遍历之前，和为0的出现次数为1
        int count = 0, pre = 0;
        for (int& i : nums)
        {
            pre += i;
            if (mp.find(pre - k) != mp.end())
                count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }
};