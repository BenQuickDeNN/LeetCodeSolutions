#include <vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        const size_t n = A.size();
        if (n <= 1)
        {
            return true;
        }
        int tri = 0;
        if (A[0] < A[1])
        {
            tri = -1;
        }
        else if (A[0] > A[1])
        {
            tri = 1;
        }
        for (size_t i = 1; i < n; ++i)
        {
            if (A[i - 1] < A[i])
            {
                if (tri == 1)
                {
                    return false;
                }
                tri = -1;
            }
            else if (A[i - 1] > A[i])
            {
                if (tri == -1)
                {
                    return false;
                }
                tri = 1;
            }
        }
        return true;
    }
};