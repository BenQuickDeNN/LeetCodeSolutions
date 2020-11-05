#include <vector>
using namespace std;
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int high = 1, low = *cont.rbegin();
        for(int i = cont.size() - 2; i >= 0; --i){
            high += low * cont[i];
            swap(low, high);
        }
        return vector<int>{low, high};
    }
};