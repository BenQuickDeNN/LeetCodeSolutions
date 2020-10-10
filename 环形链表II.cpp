#include <cstdlib>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针
        ListNode *slow = head, *fast = head;
        while (fast != NULL)
        {
            slow = slow->next;
            if (fast->next == NULL)
                return NULL;
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode *ptr = head;
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};