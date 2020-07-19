#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        // 搜索问题
        // 可以使用动态规划
        /* 初始化 */
        const int n = nums.size();
        if (n == 0)
            return 0;
        // rec[i][j] 表示区间i-1到j-1的最大价值
        vector<vector<int>> rec(n + 2, vector<int>(n + 2, 0));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        // 复制元素
        copy(&nums[0], &nums[0] + n, val.begin() + 1);
        //for (int i = 0; i < n; i++)
        //    val[i + 1] = nums[i];
        /* 开始递进，从中间开始搜索 */
        int sum;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 2; j <= n + 1; j++)
                for (int k = i + 1; k < j; k++)
                {
                    sum = val[i] * val[k] * val[j]; // 计算价值
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
        return rec[0][n + 1];
    }
};