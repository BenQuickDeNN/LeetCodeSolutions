#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
    string getDigits(const string& s, size_t& ptr)
    {
        string str = "";
        while (isdigit(s[ptr]))
            str.push_back(s[ptr++]);
        return str;
    }
    string getString(const vector<string>& v)
    {
        string ret;
        for (const auto& s : v)
            ret += s;
        return ret;
    }
public:
    string decodeString(string s) {
        // 使用栈存储字符串

        vector<string> stk;
        vector<string> sub;
        size_t ptr = 0;

        while (ptr < s.size())
        {
            char c = s[ptr];
            if (isdigit(c)) // 如果这个字符是数字
                stk.emplace_back(getDigits(s, ptr));
            else if (isalpha(c) || c == '[') // 如果这个字符是一个字母
                stk.push_back(string(1, s[ptr++]));
            else // 当前字符为右括号
            {
                ++ptr;
                // 清空sub
                sub.clear();
                // 括号内的内容都要出栈
                while (stk.back() != "[")
                {
                    sub.emplace(sub.begin(), stk.back());
                    stk.pop_back();
                }
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前sub对应的字符串出现的次数
                int n = stoi(stk.back());
                // 数字出栈
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (n--)
                    t += o;
                // 将构造好的字符串装回栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
};