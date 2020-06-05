#include <vector>
using namespace std;
enum DIR
{
    EAST,
    SOUTH,
    WEST,
    NORTH
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty()) return ret;
        const int Y = matrix.size();
        const int X = matrix[0].size();
        const int maxStep = Y * X;
        if (X == 1)
        {
            for (int s = 0; s < maxStep; s++)
                ret.push_back(matrix[s][0]);
            return ret;
        }
        int Ystart = 1, Yend = Y - 1;
        int Xstart = 0, Xend = X - 1;
        DIR dir = EAST;
        for (int s = 0, y = 0, x = 0; s < maxStep; s++)
        {
            ret.push_back(matrix[y][x]);
            switch (dir)
            {
            case EAST:
                if (x < Xend)
                    ++x;
                if (x == Xend)
                {
                    --Xend;
                    dir = SOUTH;
                }
                break;
            case SOUTH:
                if (y < Yend)
                    ++y;
                if (y == Yend)
                {
                    --Yend;
                    dir = WEST;
                }
                break;
            case WEST:
                if (x > Xstart)
                    --x;
                if (x == Xstart)
                {
                    ++Xstart;
                    dir = NORTH;
                }
                break;
            case NORTH:
                if (y > Ystart)
                    --y;
                if (y == Ystart)
                {
                    ++Ystart;
                    dir = EAST;
                }
                break;
            default:
                break;
            }
        }
        return ret;
    }
};