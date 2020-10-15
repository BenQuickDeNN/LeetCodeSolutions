#include <cstdlib>
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
    void dfs(Node *node, vector<Node*> &nodes)
    {
        if (node == NULL)
            return;
        dfs(node->left, nodes);
        nodes.push_back(node);
        dfs(node->right, nodes);
    }
public:
    Node* connect(Node* root) {
        // 中序遍历，构造节点数组
        vector<Node*> nodes;
        dfs(root, nodes);
        if (nodes.empty())
            return root;
        for (int stride = 2; stride < nodes.size(); stride <<= 1)
        {
            int start = 0;
            while (nodes[start]->next != NULL)
            { 
                ++start;
                if (start >= nodes.size())
                    break;
            }
            while (start + stride < nodes.size())
            {
                nodes[start]->next = nodes[start + stride];
                start += stride;
            }
        }
        return root;
    }
};