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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
        // 分离节点后合并
        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        ListNode* odd = odd_head;
        ListNode* even = even_head;
        while (odd != nullptr && even != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            if (odd != nullptr)
            {
                even->next = odd->next;
                even = even->next;
            }
        }
        odd = odd_head;
        while (odd->next != nullptr)
            odd = odd->next;
        odd->next = even_head;
        return odd_head;
    }
};