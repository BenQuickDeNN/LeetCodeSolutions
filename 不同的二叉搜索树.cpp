class Solution
{
public:
    int numTrees(int n)
    {
        // 使用卡塔兰数
        long long C = 1;
        for (int i = 0; i < n; i++)
            C = 2 * (2 * i + 1) * C / (i + 2);
        return (int)C;
    }
};