#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ret(2);
        ret[0] = -1;
        ret[1] = -1;

        ListNode *ptmp = head;
        vector<int> idxes;
        int idx = 0;
        int pre, curr, next;

        while (ptmp != NULL) {
            curr = ptmp->val;
            if (ptmp != head && ptmp->next != NULL) {
                next = ptmp->next->val;
                if (curr > pre && curr > next) {
                    idxes.emplace_back(idx);
                } else if (curr < pre && curr < next) {
                    idxes.emplace_back(idx);
                }
            }
            ptmp = ptmp->next;
            ++idx;
            pre = curr;
        }

        int minDist = INT_MAX;
        int maxDist = INT_MIN;

        for (int i = 1; i < idxes.size(); ++i) {
            const int dist = idxes[i] - idxes[i - 1];
            minDist = min(minDist, dist);
        }

        if (!idxes.empty()) {
            maxDist = max(maxDist, idxes.back() - idxes.front());
        }

        if (minDist != INT_MAX) {
            ret[0] = minDist;
        }
        if (maxDist != INT_MIN && maxDist != 0) {
            ret[1] = maxDist;
        }

        return ret;
    }
};