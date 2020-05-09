class Solution {
    int quwei(const int& n)
    {
        int m = n;
        int sum = 0;
        while (m > 0)
        {
            sum += (m % 10) * (m % 10);
            m /= 10;
        }                                                                                                                                      
        return sum;
    }
public:
    bool isHappy(int n) {
        /* 使用快慢指针法 */
        int slow = 0, fast = 0;
        int i = 1;
        fast = quwei(quwei(n));
        slow = quwei(n);
        while (true)
        {
            if (fast == 1)
                return true;
            else if (fast == slow)
                return false;
            fast = quwei(quwei(fast));
            slow = quwei(slow);
        }
        return false;
    }
};

int main ()
{
    Solution sol;
    sol.isHappy(19);
    return 0;
}