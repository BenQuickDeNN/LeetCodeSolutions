#include <cstdlib>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode root(0);
        root.next = head;
        ListNode* p_mv = head;
        ListNode* p_prev;
        while (p_mv->next != NULL)
        {
            p_prev = root.next;
            root.next = p_mv->next;
            p_mv->next = root.next->next; 
            root.next->next = p_prev;
        }
        return root.next;
    }
};