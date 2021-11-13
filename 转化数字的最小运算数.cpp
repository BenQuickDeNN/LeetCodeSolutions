#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
    int istart;
    int igoal;
    int minOps = INT_MAX;
    vector<int> *pnums = NULL;
    set<int> path;
    void dfs(const int & i, const int & x, const int & ops) {
        if (x == igoal) {
            minOps = min(minOps, ops);
        } else if (x == istart && ops > 0) {
            return;
        } else {
            set<int>::iterator it = path.find(x);
            if (it != path.end()) {
                return;
            }
            path.insert(x);
            for (int j = 0; j < pnums->size(); ++j) {
                if (x < igoal) dfs(j, x + pnums->at(i), ops + 1);
                if (x > igoal) dfs(j, x - pnums->at(i), ops + 1);
                dfs(j, x ^ pnums->at(i), ops + 1);
            }
            path.erase(it);
        }
    }
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        istart = start;
        igoal = goal;
        pnums = &nums;
        int x = start;
        for (int i = 0; i < nums.size(); ++i) {
            dfs(i, x, 0);
        }
        if (minOps == INT_MAX) {
            return -1;
        }
        return minOps;
    }
};