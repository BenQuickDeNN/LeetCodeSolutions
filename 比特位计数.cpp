#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        // 动态规划 + 最高有效位
        vector<int> res(num + 1);
        int i = 0, b = 1;
        while (b <= num) {
            while (i < b && i + b <= num) {
                res[i + b] = res[i] + 1;
                ++i;
            }
            i = 0;
            b <<= 1; // b *= 2;
        }
        return res;
    }
};