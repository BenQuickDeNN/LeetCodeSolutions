#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        if (grid.empty())
            return count;
        const int Y = grid.size();
        const int X = grid[0].size();
        /* 借助队列使用广度优先搜索，统计搜索启动次数 */
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
            {
                /* 发现1 */
                if (grid[y][x] == '1')
                {
                    ++count;
                    /* 已访问过的点标记为0 */
                    grid[y][x] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push(make_pair(y, x));
                    /* 开始搜索 */
                    while (!neighbors.empty())
                    {
                        pair<int, int> yx = neighbors.front();
                        neighbors.pop();
                        int yy = yx.first;
                        int xx = yx.second;
                        /* 上 */
                        if (yy > 0 && grid[yy - 1][xx] == '1')
                        {
                            neighbors.push(make_pair(yy - 1, xx));
                            grid[yy - 1][xx] = '0';
                        }
                        /* 下 */
                        if (yy < Y - 1 && grid[yy + 1][xx] == '1')
                        {
                            neighbors.push(make_pair(yy + 1, xx));
                            grid[yy + 1][xx] = '0';
                        }
                        /* 左 */
                        if (xx > 0 && grid[yy][xx - 1] == '1')
                        {
                            neighbors.push(make_pair(yy, xx - 1));
                            grid[yy][xx - 1] = '0';
                        }
                        /* 右 */
                        if (xx < X - 1 && grid[yy][xx + 1] == '1')
                        {
                            neighbors.push(make_pair(yy, xx + 1));
                            grid[yy][xx + 1] = '0';
                        }
                    }
                }
            }
        return count;
    }
};