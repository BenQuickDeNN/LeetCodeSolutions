#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        // 按字符分组
        int ptr = 0, n = s.size(), last = 0, ans = 0;
        while (ptr < n)
        {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c)
            {
                ++ptr;
                ++count;
            }
            ans += min(count, last);
            last = count;
        }
        return ans;
    }
};