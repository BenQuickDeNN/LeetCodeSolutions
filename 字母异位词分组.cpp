#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    using vvs = vector<vector<string>>;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> hash;
      for (auto &str: strs) {
        auto temp_str = str;
        sort(temp_str.begin(), temp_str.end());
        hash[temp_str].push_back(str);
      }
      vvs res;
      for (auto &it: hash) {
        res.push_back(std::move(it.second));
      }
      return res;
    }
};