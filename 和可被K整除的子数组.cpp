#include <vector>

using namespace std;

class Solution {
public:
   int subarraysDivByK(vector<int>& A, int K) {
        int modulus = 0;
        int ans = 0;
        vector<int> record(K, 0);
        ++record[0];
        for (const int& elem: A) {
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            modulus = ((modulus + elem) % K + K) % K;
            // 同余定理
            ans += record[modulus]++;
        }
        return ans;
    }
};