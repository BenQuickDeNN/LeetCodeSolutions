#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ret(candies.size(), false);
        int maxCandies = 0;
        for (const int& c : candies)
            if (c > maxCandies)
                maxCandies = c;
        for (int i = 0; i < candies.size(); i++)
            if (candies[i] + extraCandies >= maxCandies)
                ret[i] = true;
        return ret;
    }
};