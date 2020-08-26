#include <vector>
#include <string>
using namespace std;
static const string strMap[10] = {
    "_",
    "!@#",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};
class Solution {
    void backtrack(vector<string> &combinations, const string &digits, 
        const size_t &idx, string &combination)
    {
        if (idx == digits.size())
            combinations.push_back(combination);
        else
        {
            char digit = digits[idx];
            const string &letters = strMap[digit - '0'];
            for (const char &letter : letters)
            {
                combination.push_back(letter);
                backtrack(combinations, digits, idx + 1, combination);
                combination.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // 回溯法
        vector<string> combinations;
        if (digits.empty())
            return combinations;
        string combination;
        backtrack(combinations, digits, 0, combination);
        return combinations;
    }
};