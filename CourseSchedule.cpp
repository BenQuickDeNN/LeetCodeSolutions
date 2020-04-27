#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    vector<int> nexts;
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /* 问题的本质是拓扑排序 */
        /* 如果能实现拓扑排序，那么问题是可解的 */
        /* 不停的删除入度为0的顶点，如果删不完，说明有环 */
        /* 构造入度表 */
        vector<int> inDegree(numCourses, 0);
        vector<Node> nodes(numCourses);
        /* 统计节点入度，并记录传递关系 */
        for (int i = 0; i < prerequisites.size(); i++)
        {
            inDegree[prerequisites[i][1]]++;
            nodes[prerequisites[i][0]].nexts.emplace_back(prerequisites[i][1]);
        }
        /* 将入度为0的点加入队列 */
        queue<int> queIn;
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                queIn.emplace(i);
        /* 排空队列 */
        int iEnd;
        while (!queIn.empty())
        {
            iEnd = nodes[queIn.front()].nexts.size();
            for (int i = 0; i < iEnd; i++)
            {
                inDegree[nodes[queIn.front()].nexts[i]]--;
                if (inDegree[nodes[queIn.front()].nexts[i]] == 0)
                    queIn.emplace(nodes[queIn.front()].nexts[i]);
            }
            queIn.pop();
        }
        /* 检查是否还有入度不为0的点 */
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] > 0)
                return false;
        return true;
    }
};