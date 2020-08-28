#include <string>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (const char &c : moves)
            switch (c)
            {
            case 'R': ++x; break;
            case 'L': --x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
            default: break;
            }
        return x == 0 && y == 0;
    }
};