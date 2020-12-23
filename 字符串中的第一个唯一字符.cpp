#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        const int num = 26;
        unsigned int count[num] = {0}, indexes[num] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            const char & c = s[i];
            const char c_a = c - 'a';
            ++count[c_a];
            indexes[c_a] = i;
        }
        unsigned int ans = -1;
        for (int i = 0; i < num; ++i)
        {
            if (count[i] == 1)
            {
                ans = min(ans, indexes[i]);
            }
        }
        return (int)ans;
    }
};