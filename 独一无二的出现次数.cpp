#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (const int &num : arr)
            if (counts.find(num) == counts.end())
                counts[num] = 1;
            else
                ++counts[num];
        unordered_set<int> set;
        for (auto &count : counts)
            if (set.find(count.second) == set.end())
                set.insert(count.second);
            else
                return false;
        return true;
    }
};