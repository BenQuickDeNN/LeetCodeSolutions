#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int res = 0;
        unordered_map<int,int> hashmap; // key:num, val:length
        for (int i = 0; i < nums.size(); ++i)
            if (hashmap.find(nums[i]) == hashmap.end())
            {
                /* 如果 hashmap中不存在nums[i] */
                int left = 0, right = 0;
                if (hashmap.find(nums[i] - 1) != hashmap.end())
                    left = hashmap[nums[i] - 1];
                if (hashmap.find(nums[i] + 1) != hashmap.end())
                    right = hashmap[nums[i] + 1];
                const int len = left + right + 1;
                hashmap[nums[i]] = len;
                if (left != 0)
                    hashmap[nums[i] - left] = len;
                if (right != 0)
                    hashmap[nums[i] + right] = len;
                res = max(res, len);
            }
        /* 打印hashmap的值，方便了解原理 */
        /*
        for (int i = 0; i < nums.size(); ++i)
            if (hashmap.find(nums[i]) != hashmap.end())
                cout << "key=" << nums[i] << ", len=" << hashmap[nums[i]] << endl;
        */
        return res;
    }
};