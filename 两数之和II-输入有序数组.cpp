#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ret(2);
        // 使用双指针
        int left = 0, right = numbers.size() - 1;
        int tmpSum;
        while (left < right)
        {
            tmpSum = numbers[left] + numbers[right];
            if (tmpSum == target)
            {
                ret[0] = left + 1;
                ret[1] = right + 1;
                break;
            }
            else if (tmpSum < target)
                ++left;
            else
                --right;
        }
        return ret;
    }
};