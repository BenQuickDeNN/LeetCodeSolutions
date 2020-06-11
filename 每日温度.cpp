#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ret(T.size(), 0);
        // 使用单调栈
        stack<pair<int, int>> dates;
        for (int i = 0; i < T.size(); i++)
        {
            while (!dates.empty() && T[i] > dates.top().second)
            {
                ret[dates.top().first] = i - dates.top().first;
                dates.pop();
            }
            dates.emplace(make_pair(i, T[i]));
        }
        return ret;
    }
};