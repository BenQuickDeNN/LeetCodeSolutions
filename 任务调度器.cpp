#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 排序法
        vector<int> freq(26);
        for (char c : tasks) freq[c - 'A']++;

        sort(freq.begin(), freq.end());
        int res = (n + 1) * (freq[25] - 1);
        for (int i = 25; i >= 0; --i)
            if (freq[i] == freq[25]) res++;
        return max(res, (int)tasks.size());
    }
};