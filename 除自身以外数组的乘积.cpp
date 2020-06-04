#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*利用索引左侧所有数字的乘积和右侧所有数字的乘积（即前缀与后缀）相乘得到答案。*/
        /* 使用左右乘积列表 */
        vector<int> L(nums.size(), 0), R(nums.size(), 0);
        vector<int> ret(nums.size());
        L[0] = 1;
        ret[0] = 1;
        for (int i = 1; i < nums.size(); i++)
            ret[i] = nums[i - 1] * ret[i - 1];
        R[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
            ret[i] = nums[i + 1] * ret[i + 1];
        for (int i = 0; i < ret.size(); i++)
            ret[i] = L[i] * R[i];
        return ret;
    }
};

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++)
            answer[i] = nums[i - 1] * answer[i - 1];

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};