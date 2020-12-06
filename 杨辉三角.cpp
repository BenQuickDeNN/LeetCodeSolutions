#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        for (int r = 0; r < numRows; ++r)
        {
            ans[r].resize(r + 1);
            if (r == 0)
            {
                ans[r][0] = 1;
            }
            else
            {
                for (size_t c = 0; c < ans[r].size(); ++c)
                {
                    if (c == 0 || c == ans[r].size() - 1)
                    {
                        ans[r][c] = 1;
                    }
                    else
                    {
                        ans[r][c] = ans[r - 1][c - 1] + ans[r - 1][c];
                    }
                }
            }
        }
        return ans;
    }
};