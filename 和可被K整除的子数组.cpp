#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    /* 深度优先搜索 */
    
    int dp_search(const vector<int>& A, const int& idx, const int& max_idx, const int& K, int& count)
    {
        if (idx > max_idx)
            return 0;
        /* 判断当前元素能否整除K */
        int tmp_sum = A[idx];
        if (tmp_sum % K == 0)
            ++count;
        /* 判断当前元素与后面元素的和能否整除K */
        tmp_sum += + dp_search(A, idx + 1, max_idx, K, count);
        if (tmp_sum % K == 0)
            ++count;
        return tmp_sum;
    }
public:
   int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (int elem: A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            // 同余定理
            if (record.find(modulus) != record.end()) 
            {
                ans += record[modulus];
                //cout<<"elem="<<elem<<",sum="<<sum<<",";
                //cout<<"record["<<modulus<<"]="<<record[modulus]<<endl;
            }
            ++record[modulus];
        }
        return ans;
    }
};