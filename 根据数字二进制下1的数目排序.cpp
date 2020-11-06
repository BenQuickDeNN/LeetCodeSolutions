#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const int &a, const int &b)
{
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 32; ++i)
    {
        count1 += (a >> i) & 1;
        count2 += (b >> i) & 1;
    }
    if (count1 < count2)
        return true;
    else if (count1 > count2)
        return false;
    else
        return a < b;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // 暴力法
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};