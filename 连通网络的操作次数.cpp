#include <vector>
using namespace std;
class Solution {
    vector<vector<int>> edges;
    vector<int> used;

    void dfs(const int &_u)
    {
        used[_u] = true;
        for (int &v : edges[_u])
        {
            if (!used[v])
            {
                dfs(v);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // 如果边的个数少于n-1，那么肯定无法完全连接
        const int m = connections.size();
        if (m < n - 1)
        {
            return -1;
        }
        // 连通分量：互相连通的节点和边组成的集合

        edges.resize(n);
        for (const auto& conn : connections)
        {
            edges[conn[0]].push_back(conn[1]);
            edges[conn[1]].push_back(conn[0]);
        }

        used.resize(n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                dfs(i);
                ++ans;
            }
        }

        return ans - 1;
    }
};