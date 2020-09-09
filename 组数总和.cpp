#include <vector>
using namespace std;
class Solution {
    int Target;
    void dfs(vector<vector<int>>& res, vector<int>& buf, 
        const vector<int> & candidates, const int & idx, const int & sum)
    {
        if (idx < 0 || idx >= candidates.size())
            return;
        const int num = candidates[idx];
        const int sum_new = sum + num;
        buf.push_back(num);
        if (sum_new == Target)
            res.emplace_back(buf);
        else if (sum_new < Target)
            for (int i = idx; i < candidates.size(); ++i)
                dfs(res, buf, candidates, i, sum_new);
        buf.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 深度优先搜索
        Target = target;
        vector<vector<int>> res;
        vector<int> buf;
        for (int i = 0; i < candidates.size(); ++i)
            dfs(res, buf, candidates, i, 0);
        return res;
    }
};