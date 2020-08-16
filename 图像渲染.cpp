#include <vector>
using namespace std;
class Solution {
    void dfs(vector<vector<int>> &image, vector<vector<bool>> &visited, const int &sr, const int &sc, const int &startColor, const int &newColor)
    {
        // check inbound
        if (sr >= image.size())
            return;
        else if (sr < 0)
            return;
        if (sc >= image[0].size())
            return;
        else if (sc < 0)
            return;
        // check visited
        if (visited[sr][sc])
            return;
        visited[sr][sc] = true;
        // check color
        int &color = image[sr][sc];
        if (color != startColor)
            return;
        else
            color = newColor;
        // check neigbors
        dfs(image, visited, sr - 1, sc, startColor, newColor);
        dfs(image, visited, sr + 1, sc, startColor, newColor);
        dfs(image, visited, sr, sc - 1, startColor, newColor);
        dfs(image, visited, sr, sc + 1, startColor, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // 深度优先搜索
        if (image.empty())
            return image;
        const int startColor = image[sr][sc];
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, visited, sr, sc, startColor, newColor);
        return image;
    }
};