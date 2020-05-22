#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        TreeNode* root,*pre;
        bool mark=0;
        stack<TreeNode*> s;
        int cur1=0,cur2=0,l1=preorder.size(),l2=inorder.size();
        root=new TreeNode(preorder[cur1++]);
        s.push(root);
        pre=root;
        while(cur1<l1){
            while(!s.empty()&&s.top()->val==inorder[cur2]){
                pre=s.top();
                s.pop();
                cur2++;
                mark=1;
            }
            if(mark){
                pre->right=new TreeNode(preorder[cur1++]);
                pre=pre->right;
                s.push(pre);
                mark=0;
            }else{
                pre->left=new TreeNode(preorder[cur1++]);
                pre=pre->left;
                s.push(pre);
            }
        }
        return root;
    }
};