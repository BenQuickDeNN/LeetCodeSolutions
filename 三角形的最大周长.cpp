#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        // 排序+贪心
        sort(A.begin(), A.end());
        for (int i = (int)A.size() - 1; i >= 2; --i)
            if (A[i - 2] + A[i - 1] > A[i])
                return A[i - 2] + A[i - 1] + A[i];
        return 0;
    }
};