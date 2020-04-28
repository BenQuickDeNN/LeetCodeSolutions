#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        /* 使用分组异或方法 */
        /* 先对所有数字进行一次异或，得到两个出现一次的数字的异或值 */
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        /* 在异或结果中找到任意为1的位 */
        int div = 1;
        while (!(div & ret))
            div <<= 1;
        /* 根据这一位对所有的数字进行分组，在每个组内进行异或操作，得到两个数字 */
        int a = 0;
        int b = 0;
        for (int n : nums)
            if (n & div)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};