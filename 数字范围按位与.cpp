class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // 使用位移法
        // 将两个数字不断向右移动，直到数字相等，即数字被缩减为它们的公共前缀。然后，通过将公共前缀向左移动，将零添加到公共前缀的右边以获得最终结果。
        int shift = 0;
        // 寻找公共前缀
        while (m < n)
        {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};