#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        // 使用动态规划
        int res = 0;
        int len = s.length();
        int *dp = new int[len];
        memset(dp, 0, sizeof(int) * len);
        for(int i = 1; i < len; ++i){
            if(s[i] == ')'){
                if(s[i - 1] == '('){
                    dp[i] = (i > 2 ? dp[i - 2] : 0) + 2;
                }else if(i - dp[i - 1] > 0 && s[i - dp[i -1] - 1] == '('){
                    dp[i] = dp[i - 1] + ((i - dp[i -1] > 2) ? dp[i - dp[i -1] - 2] : 0) + 2;
                }
            } 
            res = max(dp[i], res);
        }
        return res;
    }
};