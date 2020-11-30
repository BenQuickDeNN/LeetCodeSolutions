#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reorganizeString(string S) {
        // 基于计数的贪心算法
        // 重构字符串时，需要根据每个字母在字符串中出现的次数处理每个字母放置的位置。如果出现次数最多的字母可以在重新排布之后不相邻，则可以重新排布字母使得相邻的字母都不相同。如果出现次数最多的字母过多，则无法重新排布字母使得相邻的字母都不相同。
        if (S.length() < 2)
            return S;
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = S.length();
        for (int i = 0; i < length; i++) {
            char c = S[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2)
            return "";
        string reorganizeArray(length, ' ');
        int evenIndex = 0, oddIndex = 1;
        int halfLength = length / 2;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length) {
                reorganizeArray[oddIndex] = c;
                counts[i]--;
                oddIndex += 2;
            }
            while (counts[i] > 0) {
                reorganizeArray[evenIndex] = c;
                counts[i]--;
                evenIndex += 2;
            }
        }
        return reorganizeArray;
    }
};