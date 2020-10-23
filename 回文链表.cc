#include <cstdlib>
#include <vector>
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
        vector<int> stk;
        ListNode *p = head;
        while (p != NULL)
        {
            stk.push_back(p->val);
            p = p->next;
        }
        p = head;
        for (int i = stk.size() - 1; i >= 0; --i)
        {
            if (stk[i] != p->val)
                return false;
            p = p->next;
        }
        return true;
    }
};