#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int n = heights.size();
        int ret = 0;
        for(int i = 0; i < n; ++i){
            // 遇见比较矮的平台就重新计算最大面积
            while(stk.top() != -1 && heights[stk.top()] > heights[i])
            {
                int tmp = stk.top();
                stk.pop();
                ret = max(ret, heights[tmp] * (i - 1 - stk.top()));
            }
            stk.push(i);
        }
        while(stk.top() != -1){
            int tmp = stk.top();
            stk.pop();
            ret = max(ret, heights[tmp] * (n - 1 - stk.top()));
        }
        return ret;
    }
};