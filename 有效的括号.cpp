#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (size_t i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '{' || c == '[' || c == '(')
                stk.push(c);
            else
                if (stk.empty())
                    return false;
                else if ((c == '}' && stk.top() == '{') ||
                    (c == ']' && stk.top() == '[') ||
                    (c == ')' && stk.top() == '('))
                    stk.pop();
                else
                    return false;
        }
        return stk.empty();
    }
};