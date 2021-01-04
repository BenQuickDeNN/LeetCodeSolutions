class Solution {
public:
    int fib(int n) {
        int F0 = 0, F1 = 1;
        if (n == 0)
        {
            return F0;
        }
        else if (n == 1)
        {
            return F1;
        }
        int F2;
        for (int i = 2; i <= n; ++i)
        {
            F2 = F0 + F1;
            F0 = F1;
            F1 = F2;
        }
        return F2;
    }
};