#include <vector>
using namespace std;
class Solution {
    int K;
    int N;
    // 深度优先搜索
    void dfs(vector<vector<int>>& res, vector<int>& buf, const int& n,  const int& k, const int& i)
    {
        buf.push_back(i);
        const int _k = k + 1;
        const int _n = n + i;
        if (_k == K && _n == N && !buf.empty())
            res.emplace_back(buf);
        else if (_k < K && _n < N)
            for (int j = i + 1; j < 10; ++j)
                dfs(res, buf, _n, _k, j);
        if (!buf.empty())
            buf.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        K = k;
        N = n;
        vector<vector<int>> ret;
        vector<int> buf;
        for (int i = 1; i < 10; ++i)
            dfs(ret, buf, 0, 0, i);
        return ret;
    }
};