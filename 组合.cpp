#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> & ans, vector<int> & tmp, 
        const int& cur, const int& n, const int& k)
    {
        // 剪枝：tmp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 tmp
        if (tmp.size() + (n - cur + 1) < k) 
            return;
        // 记录合法的答案
        if (tmp.size() == k) 
        {
            ans.push_back(tmp);
            return;
        }
        // 考虑选择当前位置
        tmp.push_back(cur);
        dfs(ans, tmp, cur + 1, n, k);
        tmp.pop_back();
        // 考虑不选择当前位置
        dfs(ans, tmp, cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> ans;
        dfs(ans, tmp, 1, n, k);
        return ans;
    }
};