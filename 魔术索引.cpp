#include <vector>
using namespace std;
class Solution
{
public:
    int findMagicIndex(vector<int> &nums)
    {
        const int n = nums.size();
        for (int ret = 0; ret < n; ret++)
            if (ret == nums[ret])
                return ret;
        return -1;
    }
};