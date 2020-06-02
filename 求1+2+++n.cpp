class Solution {
public:
    int sumNums(int n) {
        /* 不能用乘除法，也不能用循环，所以只能递归 */
        n && (n += sumNums(n - 1)); // 等效于if (n && (n += sumNums(n - 1)))
        return n;
    }
};