#include <vector>
using namespace std;
class Solution {
    int Y, X;
    bool isGameOver;
    bool inBound(const int &y, const int &x)
    {
        if (y < 0 || y >= Y)
            return false;
        if (x < 0 || x >= X)
            return false;
        return true;
    }
    char countMines(const vector<vector<char>>& board, const int &y, const int &x)
    {
        char count = '0';
        for (int yy = y - 1; yy <= y + 1; ++yy)
            for (int xx = x - 1; xx <= x + 1; ++xx)
            {
                if (!inBound(yy, xx))
                    continue;
                count += board[yy][xx] == 'M';
            }
        return count;
    }
    void revealed(vector<vector<char>>& board, const int &y, const int &x)
    {
        if (isGameOver)
            return;
        if (!inBound(y, x))
            return;
        if (board[y][x] == 'M')
        {
            // game over
            board[y][x] = 'X';
            isGameOver = true;
            return;
        }
        else if (board[y][x] == 'E')
        {
            // count how many mines around this position
            char count = countMines(board, y, x);
            if (count == '0')
            {
                board[y][x] = 'B';
                // reveal neighbors
                for (int yy = y - 1; yy <= y + 1; ++yy)
                    for (int xx = x - 1; xx <= x + 1; ++xx)
                        revealed(board, yy, xx);
            }
            else
                board[y][x] = count;
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty())
            return board;
        Y = board.size();
        X = board[0].size();
        const int y = click[0];
        const int x = click[1];
        isGameOver = false;
        revealed(board, y, x);
        return board;
    }
};