#include <cstdlib>
#include <stack>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode *p = head;
        while (p != NULL)
        {
            stk.push(p->val);
            p = p->next;
        }
        p = head;
        while (!stk.empty())
            if (p->val != stk.top())
                return false;
            else
            {
                stk.pop();
                p = p->next;
            }
        return true;
    }
};