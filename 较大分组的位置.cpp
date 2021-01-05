#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int start, end;
        vector<vector<int>> ans;
        char c = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != c)
            {
                if (c != 0 && (end - start) > 1)
                {
                    ans.push_back({start, end});
                }
                c = s[i];
                start = i;
                end = i;
            }
            else
            {
                ++end;
            }
        }
        if ((end - start) > 1)
        {
            ans.push_back({start, end});
        }
        return ans;
    }
};