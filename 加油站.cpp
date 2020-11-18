#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 遍历分别从每个加油站出发的情况
        int ans = -1;
        const int N = gas.size();
        for (int start = 0; start < N; ++start)
        {
            int tank = gas[start];
            tank -= cost[start];
            for (int i = (start + 1) % N; i != start; i = (i + 1) % N)
            {
                if (tank < 0)
                    break;
                tank += gas[i];
                tank -= cost[i];
            }
            if (tank >= 0)
            {
                ans = start;
                break;
            }
        }
        return ans;
    }
};