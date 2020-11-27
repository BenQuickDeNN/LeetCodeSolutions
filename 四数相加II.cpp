#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // 分组+哈希表
        int ans = 0;
        unordered_map<int, int> counts;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < B.size(); ++j)
            {
                int sum = A[i] + B[j];
                if (counts.find(sum) == counts.end())
                    counts[sum] = 1;
                else
                    ++counts[sum];
            }
        for (int i = 0; i < C.size(); ++i)
            for (int j = 0; j < B.size(); ++j)
            {
                int sum = - (C[i] + D[j]);
                if (counts.find(sum) != counts.end())
                    ans += counts[sum];
            }
        return ans;
    }
};