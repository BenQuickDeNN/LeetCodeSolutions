#include <string>

using namespace std;

class Solution {
    char delCount = 0;
public:
    bool validPalindrome(string s) {
        unsigned short i = 0, j = s.size() - 1;
        const char* str = s.c_str();
        while (i < j)
        {
            if (str[i] != str[j]) 
                if (delCount)
                    return false;
                else
                {
                    delCount++;
                    return validPalindrome(s.substr(i, j - i)) ||
                        validPalindrome(s.substr(i + 1, j - i));
                }
            ++i; --j;
        }
        return true;
    }
};