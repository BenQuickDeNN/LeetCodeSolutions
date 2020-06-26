#include <cstdlib>
#include <unordered_map>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        // 使用unordered_map作为缓冲区
        unordered_map<int, ListNode*> buf;
        ListNode* p = head;
        ListNode* p_old;
        while (p != NULL)
            if (buf.find(p->val) != buf.end())
            {
                // 删除冗余节点
                p_old->next = p->next;
                p->next = NULL;
                p = p_old->next;
            }
            else
            {
                buf[p->val] = p;
                p_old = p;
                p = p->next;
            }
        return head;
    }
};