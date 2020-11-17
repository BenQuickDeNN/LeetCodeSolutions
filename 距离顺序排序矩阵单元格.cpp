#include <vector>
#include <queue>
using namespace std;
class Solution {
    
    int R, C;
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        this->R = C;
        this->C = C;
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<vector<int>> ans;
        // 广度优先搜索
        queue<pair<int, int>> q;
        q.push({r0, c0});
        visited[r0][c0] = true;
        vector<int> tmp(2);
        while (!q.empty())
        {
            auto loc = q.front();
            q.pop();
            tmp[0] = loc.first;
            tmp[1] = loc.second;
            ans.emplace_back(tmp);
            if (loc.first - 1 >= 0)
                if (!visited[loc.first - 1][loc.second])
                {
                    q.push({loc.first - 1, loc.second});
                    visited[loc.first - 1][loc.second] = true;
                }
            if (loc.first + 1 < R)
                if (!visited[loc.first + 1][loc.second])
                {
                    q.push({loc.first + 1, loc.second});
                    visited[loc.first + 1][loc.second] = true;
                }
            if (loc.second - 1 >= 0)
                if (!visited[loc.first][loc.second - 1])
                {
                    q.push({loc.first, loc.second - 1});
                    visited[loc.first][loc.second - 1] = true;
                }
            if (loc.second + 1 < C)
                if (!visited[loc.first][loc.second + 1])
                {
                    q.push({loc.first, loc.second + 1});
                    visited[loc.first][loc.second + 1] = true;
                }
        }
        return ans;
    }
};