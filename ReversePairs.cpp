#include <vector>

using namespace std;

/* 统计数组中逆序对的个数 */
class Solution {
    int mergeSort(vector<int>& nums, vector<int>& tmp, const int& l, const int& r)
    {
        if (l >= r)
            return 0;
        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        /* 寻找两个数组之间的逆序对 */
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
            {
                tmp[pos] = nums[i];
                ++i;
                /* num[mid + 1]与nums[j]之间的数都比nums[i]小，可与nums[i]构成逆序对 */
                inv_count += (j - (mid + 1));
            }
            else
            {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        /* 如果在上一步结束后, i < mid，说明i之后的数都比nums[j]大，也构成逆序对 */
        inv_count += (mid - i + 1) * (j - (mid + 1));
        /* 继续合并剩下的元素 */
        for (int k = i; k <= mid; ++k)
            tmp[pos++] = nums[k];
        for (int k = j; k <= r; ++k)
            tmp[pos++] = nums[k];
        /* 将合并结果写回nums */
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        vector<int> tmp(nums.size());
        return mergeSort(nums, tmp, 0, nums.size() - 1);
    }
};

/* 官方解 */
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};