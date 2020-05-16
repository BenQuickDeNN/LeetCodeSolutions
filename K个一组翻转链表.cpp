#include <cstdlib>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        /* 使用栈存储k个节点，空间复杂度不超过k，为常量级 */
        /* 时间复杂度为O(n) */
        ListNode root(0);
        root.next = head;
        ListNode* tail = &root;
        stack<ListNode*> ln_stk;
        while (head != NULL || ln_stk.size() == k)
        {
            if (ln_stk.size() == k)
            {
                while (!ln_stk.empty())
                {
                    tail->next = ln_stk.top();
                    tail = tail->next;
                    ln_stk.pop();
                }
                tail->next = head;
                if (head == NULL)
                    break;
            }
            ln_stk.emplace(head);
            head = head->next;
        }
        return root.next;
    }
};