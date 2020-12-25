#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 排序 + 贪心
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        for (size_t i = 0, j = 0; i < g.size() && j < s.size(); ++j)
        {
            if (g[i] <= s[j])
            {
                ++i;
                ++ans;
            }
        }
        return ans;
    }
};