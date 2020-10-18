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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        vector<ListNode*> nodes;
        while (head != NULL)
        {
            nodes.push_back(head);
            head = head->next;
        }
        const int idx = nodes.size() - n;
        if (idx < 0)
            return NULL;
        else if (idx > 0)
        {
            nodes[idx - 1]->next = nodes[idx]->next;
            nodes[idx]->next = NULL;
            nodes[idx] = NULL;
            return nodes.front();
        }
        else
        {
            nodes[idx]->next = NULL;
            nodes[idx] = NULL;
            if (idx + 1 < nodes.size())
                return nodes[idx + 1];
            else
                return NULL;
        }
    }
};