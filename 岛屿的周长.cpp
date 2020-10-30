#include <vector>
using namespace std;
class Solution {
    int Y, X;
    int sum;
    vector<vector<bool>> visited;
    void dfs(const vector<vector<int>>& grid, const int &y, const int &x)
    {
        if (y < 0 || y >= Y)
            return;
        else if (x < 0 || x >= X)
            return;
        if (visited[y][x])
            return;
        visited[y][x] = true;
        if (!grid[y][x])
            return;
        if (y == 0 || !grid[y - 1][x])
            ++sum;
        if (y == Y - 1 || !grid[y + 1][x])
            ++sum;
        if (x == 0 || !grid[y][x - 1])
            ++sum;
        if (x == X - 1 || !grid[y][x + 1])
            ++sum;
        dfs(grid, y - 1, x);
        dfs(grid, y + 1, x);
        dfs(grid, y, x - 1);
        dfs(grid, y, x + 1);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        Y = grid.size();
        if (Y <= 0)
            return 0;
        X = grid[0].size();
        visited.resize(Y, vector<bool>(X, false));
        sum = 0;
        for (int y = 0; y < Y; ++y)
            for (int x = 0; x < X; ++x)
                dfs(grid, y, x);
        return sum;
    }
};