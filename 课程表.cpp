#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    vector<vector<int>> edges; // 边
    vector<int> indeg;         // 入度

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 拓扑排序
        // 广度优先搜索
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        // 找到入度为0的点入队
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0)
                q.push(i);

        int visited = 0;
        while (!q.empty())
        {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v : edges[u])
            {
                --indeg[v];
                if (indeg[v] == 0)
                    q.push(v);
            }
        }

        return visited == numCourses;
    }
};