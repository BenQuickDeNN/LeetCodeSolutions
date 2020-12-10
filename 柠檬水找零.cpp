#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0, count20 = 0;
        for (const auto &b : bills)
        {
            switch (b)
            {
            case 5:
                ++count5;
                break;
            case 10:
                if (count5 > 0)
                {
                    --count5;
                    ++count10;
                }
                else
                {
                    return false;
                }
                break;
            case 20:
                if (count10 > 0 && count5 > 0)
                {
                    --count10;
                    --count5;
                    ++count20;
                }
                else if (count5 >= 3)
                {
                    count5 -= 3;
                    ++count20;
                }
                else
                {
                    return false;
                }
                break;
            default:
                return false;
                break;
            }
        }
        return true;
    }
};