#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        const int n = nums.size();
        // 用哈希表，另一种方法使原地修改，但我不喜欢用
        unordered_map<int, bool> _map;
        for (int i = 1; i <= n; ++i)
        {
            _map[i] = false;
        }
        for (auto & num : nums)
        {
            _map[num] = true;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!_map[i])
                res.emplace_back(i);
        }
        return res;
    }
};