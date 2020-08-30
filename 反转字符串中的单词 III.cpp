#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        stack<char> stk;
        for (char &c : s)
        {
            if (c == ' ')
            {
                while (!stk.empty())
                {
                    ret += stk.top();
                    stk.pop();
                }
                ret += ' ';
            }
            else
                stk.push(c);
        }
        while (!stk.empty())
        {
            ret += stk.top();
            stk.pop();
        }
        return ret;
    }
};