#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 贪心 + 栈
        vector<int> vis(26), num(26);
        for (const char & c : s)
        {
            ++num[c - 'a'];
        }
        string stk;
        for (const char & c : s)
        {
            const char c_a = c - 'a';
            if (!vis[c_a])
            {
                while (!stk.empty() && stk.back() > c)
                {
                    if (num[stk.back() - 'a'] > 0)
                    {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                vis[c_a] = 1;
                stk.push_back(c);
            }
            num[c_a] -= 1;
        }
        return stk;
    }
};