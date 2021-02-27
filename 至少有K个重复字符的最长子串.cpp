#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    int k = 0;
    int dfs(const string &_s, const int &_l, const int &_r)
    {
        vector<int> cnt(26, 0);
        for (int i = _l; i <= _r; ++i)
        {
            ++cnt[_s[i] - 'a'];
        }

        char split = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] > 0 && cnt[i] < k)
            {
                split = i + 'a';
                break;
            }
        }

        if (split == 0)
        {
            return _r - _l + 1; // 子串长度
        }

        // 划分
        int i = _l;
        int ret = 0;
        while (i <= _r)
        {
            while (i <= _r && _s[i] == split)
            {
                ++i;
            }
            if (i > _r)
            {
                break;
            }
            int start = i;
            while (i <= _r && _s[i] != split)
            {
                ++i;
            }

            int length = dfs(_s, start, i - 1);
            ret = max(ret, length);
        }
        return ret;
    }
public:
    int longestSubstring(string s, int k) {
        // 分治法
        this->k = k;
        return dfs(s, 0, s.size() - 1);
    }
};