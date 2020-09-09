#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> q;
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i] != 0)
                q.push(nums[i]);
        nums.clear();
        nums.resize(n, 0);
        int k = 0;
        while (!q.empty())
        {
            nums[k++] = q.front();
            q.pop();
        }
    }
};