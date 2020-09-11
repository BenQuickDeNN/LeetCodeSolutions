#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    unordered_map<char, int> pc_count;
    string* pp;
    bool isAnagram(const string& a)
    {
        if (a.size() != pp->size())
            return false;
        unordered_map<char, int> ac_count;
        for (const char & c : a)
        {
            if (pc_count.find(c) == pc_count.end())
                return false;
            if (ac_count.find(c) == ac_count.end())
                ac_count[c] = 1;
            else
                ++ac_count[c];
        }
        for (auto & it : ac_count)
            if (it.second != pc_count.find(it.first)->second)
                return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        pc_count.clear();
        pp = &p;
        for (const char & c : p)
            if (pc_count.find(c) == pc_count.end())
                pc_count[c] = 1;
            else
                ++pc_count[c];
        // 滑动窗口
        const int n = p.size();
        vector<int> res;
        for (int i = 0; i + n <= s.size(); ++i)
        {
            if (isAnagram(s.substr(i, n)))
                res.emplace_back(i);
        }
        return res;
    }
};