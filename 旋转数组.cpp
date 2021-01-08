#include <vector>
using namespace std;
class Solution {
    int gcd(const int &_a, const int &_b)
    {
        return _a == 0 ? _b : gcd(_b % _a, _a);
    }
public:
    void rotate(vector<int>& nums, int k) {
        // 环状替换
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};