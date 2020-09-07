#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct cmp
{
    bool operator () (const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second <= b.second;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const auto & num : nums)
        {
            auto it = count.find(num);
            if (it == count.end())
                count[num] = 1;
            else
                count[num] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (const auto & it : count)
            q.push(make_pair(it.first, it.second));
        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            res.emplace_back(q.top().first);
            q.pop();
        }
        return res;
    }
};