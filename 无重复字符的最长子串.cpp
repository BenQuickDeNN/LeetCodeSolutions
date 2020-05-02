#include <string>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        char c;
        map<char, int> indexs;
        queue<char> strque;
        for (int i = 0; i < s.size(); i++)
        {
            c = s.c_str()[i];
            if (indexs.find(c) != indexs.end())
            {
                if (strque.size() > maxLen)
                    maxLen = strque.size();
                while (!strque.empty())
                {
                    indexs.erase(strque.front());
                    if (strque.front() == c)
                    {
                        strque.pop();
                        break;
                    }
                    strque.pop();
                }
            }
            else
            {
                indexs[c] = i;
                strque.emplace(c);
            }
        }
        if (strque.size() > maxLen)
            maxLen = strque.size();
        return maxLen;
        /* 用滑动窗口更快 */
    }
};