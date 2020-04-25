#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    /* 回溯法 */
    void perm(vector<vector<int>>& results, vector<int>& nums, const int& k, const int& m)
    {
        /* 所有数都填完了 */
        if (k == m)
        {
            results.emplace_back(nums);
            return;
        }
        for (int i = k; i < m; i++)
        {
            swap(nums[k], nums[i]);
            perm(results, nums, k + 1, m);
            swap(nums[k], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        perm(results, nums, 0, nums.size());
        return results;
    }
};