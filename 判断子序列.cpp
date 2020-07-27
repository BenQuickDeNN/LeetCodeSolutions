#include <string>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int p_s = 0;
        for (const char &c : t)
            if (p_s >= s.size())
                break;
            else if (c == s[p_s])
                ++p_s;
        if (p_s != s.size())
            return false;
        return true;
    }
};