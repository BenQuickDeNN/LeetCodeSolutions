#include <vector>
#include <cstdlib>
using namespace std;

class NumArray {
    vector<int> *pnums = NULL;
public:
    NumArray(vector<int>& nums) {
        pnums = &nums;
    }

    ~NumArray()
    {
        pnums = NULL;
    }
    
    int sumRange(int i, int j) {
        if (pnums == NULL)
        {
            return 0;
        }
        if (pnums->empty())
        {
            return 0;
        }

        int ans = 0;
        for (size_t k = i; k <= j && k < pnums->size(); ++k)
        {
            ans += pnums->at(k);
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */