class Solution {
public:
    double myPow(double x, int n) {
        /* 使用快速幂算法 */
        double res = 1.0;
        /* 贡献 */
        double x_contribute = x;
        bool flag_rev = false;
        long int N = (long int)n;
        if (flag_rev = (n < 0))
            N = - N;
        while (N > 0)
        {
            if (N % 2)
                res *= x_contribute;
            x_contribute *= x_contribute;
            N >>= 1;
        }
        if (flag_rev)
            res = 1.0 / res;
        return res;
    }
};