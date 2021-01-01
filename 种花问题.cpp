#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 贪心
        const size_t m = flowerbed.size();
        int count = 0;
        int prev = -1;
        // 从左向右遍历
        for (size_t i = 0; i < m; ++i)
        {
            if (flowerbed[i])
            {
                if (prev < 0)
                {
                    count += i / 2;
                }
                else
                {
                    count += (i - prev - 2) / 2;
                }
                if (count >= n)
                {
                    return true;
                }
                prev = i;
            }
        }
        if (prev < 0)
        {
            count += (m + 1) / 2;
        }
        else
        {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
};