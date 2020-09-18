#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(begin(nums), end(nums));
        do {
            ret.emplace_back(nums);
        } while (next_permutation(begin(nums), end(nums)));
        return ret;
    }
};