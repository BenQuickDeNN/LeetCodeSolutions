#include <string>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        // 求和
        size_t sum = 0;
        for (auto & c : t)
        {
            sum += c;
        }
        for (auto & c : s)
        {
            sum -= c;
        }
        return sum;
    }
};