#include <vector>
using namespace std;
class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        // 二分法
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high)
        {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high])
                high = pivot;
            else if (numbers[pivot] > numbers[high])
                low = pivot + 1;
            else
                --high;
        }
        return numbers[low];
    }
};