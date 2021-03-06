#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // 使用枚举法
        int ans = 0, mx = A[0] + 0;
        for (int j = 1; j < A.size(); ++j) {
            ans = max(ans, mx + A[j] - j);
            // 边遍历边维护
            mx = max(mx, A[j] + j);
        }
        return ans;
    }
};