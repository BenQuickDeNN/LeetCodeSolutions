#include <cstdlib>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /* 使用链表对齐法 */
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        int countA = 0;
        int countB = 0;
        /* 统计A的长度 */
        while (nodeA != NULL)
        {
            countA++;
            nodeA = nodeA->next;
        }
        /* 统计B的长度 */
        while (nodeB != NULL)
        {
            countB++;
            nodeB = nodeB->next;
        }
        /* 重置 */
        nodeA = headA;
        nodeB = headB;
        /* 调整指针位置 */
        if (countA > countB)
        {
            const int foldA = countA - countB;
            for (int i = 0; i < foldA; i++)
                nodeA = nodeA->next;
        }
        else
        {
            const int foldB = countB - countA;
            for (int i = 0; i < foldB; i++)
                nodeB = nodeB->next;
        }
        /* 比较指针是否相同 */
        while (nodeA != NULL && nodeB != NULL)
        {
            if (nodeA == nodeB)
                return nodeA;
            else
            {
                nodeA = nodeA->next;
                nodeB = nodeB->next;
            }
        }
        return NULL;
    }
};