#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        // 埃氏筛
        vector<bool> isPrime(n, true);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++ans;
                if ((long long)i * i < n)
                    for (int j = i * i; j < n; j += i)
                        isPrime[j] = false;
            }
        }
        return ans;
    }
};