#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<size_t> idxs_ji, idxs_ou;
        for (size_t i = 0; i < A.size(); ++i)
        {
            if (i % 2 == 1)
                if (A[i] % 2 == 0)
                    if (!idxs_ji.empty())
                    {
                        const size_t j = idxs_ji.back();
                        idxs_ji.pop_back();
                        A[i] += A[j];
                        A[j] = A[i] - A[j];
                        A[i] -= A[j];
                    }
                    else
                        idxs_ou.emplace_back(i);
                else { }
            else
                if (A[i] % 2 == 1)
                    if (!idxs_ou.empty())
                    {
                        const size_t j = idxs_ou.back();
                        idxs_ou.pop_back();
                        A[i] += A[j];
                        A[j] = A[i] - A[j];
                        A[i] -= A[j];
                    }
                    else
                        idxs_ji.emplace_back(i);
        }
        return A;
    }
};