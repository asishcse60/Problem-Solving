Complexity:O(n)
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connectNextPointer(TreeLinkNode *root){
    
        if(root == NULL) return;
        if(root->left)
         root->left->next = root->right;
        if(root->right)
        root->right->next = root->next?root->next->left:NULL;
        connectNextPointer(root->left);
        connectNextPointer(root->right);
    }
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
       root->next = NULL;
       connectNextPointer(root);
    }
};